"""每月末重抓训练数据（Codeforces + AtCoder），输出可直接贴进 01/04 的数字。

用法：
    python refresh_stats.py            # 打印 markdown 片段
    python refresh_stats.py --json out.json

洛谷接口现在要登录（302 循环），本脚本跳过，洛谷数字需手动填。

依赖：Python 3.8+ 标准库，无需第三方包。首次运行会缓存 problemset（约 2 MB）到
      %TEMP%\\cf-calib\\problems.json，之后走缓存；加 --refresh 强制重下。
"""

import argparse
import collections
import json
import os
import sys
import tempfile
import time
import urllib.request

CF_HANDLE = "X_moink"
AT_HANDLE = "Morgann"
CACHE = os.path.join(tempfile.gettempdir(), "cf-calib")
UA = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/126 Safari/537.36"}


def get_json(url, timeout=120):
    req = urllib.request.Request(url, headers=UA)
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        return json.loads(resp.read().decode("utf-8"))


def load_problemset(refresh=False):
    os.makedirs(CACHE, exist_ok=True)
    path = os.path.join(CACHE, "problems.json")
    if refresh or not os.path.exists(path):
        print("downloading problemset ...", file=sys.stderr)
        req = urllib.request.Request("https://codeforces.com/api/problemset.problems", headers=UA)
        with urllib.request.urlopen(req, timeout=180) as resp:
            open(path, "wb").write(resp.read())
    return {(p["contestId"], p["index"]): p for p in json.load(open(path, encoding="utf-8"))["result"]["problems"]}


def cf_stats(refresh=False):
    info = get_json(f"https://codeforces.com/api/user.info?handles={CF_HANDLE}")["result"][0]
    hist = get_json(f"https://codeforces.com/api/user.rating?handle={CF_HANDLE}")["result"]
    subs = get_json(f"https://codeforces.com/api/user.status?handle={CF_HANDLE}&from=1&count=10000")["result"]
    pr = load_problemset(refresh)

    per = collections.defaultdict(list)
    for s in subs:
        if s["problem"].get("contestId"):
            per[(s["problem"]["contestId"], s["problem"]["index"])].append(s)

    first_ok = {k: min(x["creationTimeSeconds"] for x in v if x.get("verdict") == "OK")
                for k, v in per.items() if any(x.get("verdict") == "OK" for x in v)}

    buckets = collections.Counter()
    for k in first_ok:
        r = (pr.get(k) or {}).get("rating")
        buckets[r // 100 * 100 if r else "unrated"] += 1

    monthly = {}
    for k, t in first_ok.items():
        m = time.strftime("%Y-%m", time.gmtime(t))
        d = monthly.setdefault(m, {"ac": 0, "one": 0, "ge1400": 0})
        d["ac"] += 1
        if len(per[k]) == 1:
            d["one"] += 1
        if ((pr.get(k) or {}).get("rating") or 0) >= 1400:
            d["ge1400"] += 1

    verdicts = collections.Counter(s.get("verdict") for s in subs)
    tags = collections.Counter()
    for k in first_ok:
        for t in (pr.get(k) or {}).get("tags") or []:
            tags[t] += 1

    return {
        "rating": info["rating"],
        "max_rating": info["maxRating"],
        "rank": info["rank"],
        "contests": len(hist),
        "subs": len(subs),
        "ok": verdicts["OK"],
        "ac": len(first_ok),
        "one_ac": sum(1 for k in first_ok if len(per[k]) == 1),
        "rated_ac": sum(v for k, v in buckets.items() if k != "unrated"),
        "ge1400": sum(v for k, v in buckets.items() if k != "unrated" and k >= 1400),
        "ge1500": sum(v for k, v in buckets.items() if k != "unrated" and k >= 1500),
        "buckets": {str(k): v for k, v in sorted(buckets.items(), key=lambda kv: str(kv[0]))},
        "verdicts": dict(verdicts),
        "tags": tags.most_common(12),
        "monthly": dict(sorted(monthly.items())),
        "last_contests": [
            {"date": time.strftime("%Y-%m-%d", time.gmtime(h["ratingUpdateTimeSeconds"])),
             "name": h["contestName"], "old": h["oldRating"], "new": h["newRating"], "rank": h["rank"]}
            for h in hist[-8:]
        ],
        "recent_ratings": [h["newRating"] for h in hist[-8:]],
    }


def at_stats():
    out = {}
    hist = get_json(f"https://atcoder.jp/users/{AT_HANDLE}/history/json")
    rated = [h["NewRating"] for h in hist if h.get("IsRated")]
    out["contests"] = len(hist)
    out["rated"] = len(rated)
    out["rating"] = rated[-1] if rated else None
    out["max_rating"] = max(rated) if rated else None
    out["last5"] = [(h.get("ContestName"), h.get("OldRating"), h.get("NewRating"), h.get("Performance"))
                    for h in hist[-5:]]
    subs = get_json(f"https://kenkoooo.com/atcoder/atcoder-api/v3/user/submissions?user={AT_HANDLE}&from_second=0")
    ac_problems = {s["problem_id"] for s in subs if s["result"] == "AC"}
    pos = collections.Counter()
    abc = collections.defaultdict(set)
    for pid in ac_problems:
        if pid.startswith("abc"):
            num, _, tail = pid[3:].partition("_")
            if num.isdigit():
                abc[int(num)].add(tail[0].upper())
                pos[tail[0].upper()] += 1
    out["subs"] = len(subs)
    out["ac"] = len(ac_problems)
    out["pos"] = dict(sorted(pos.items()))
    out["recent_abc"] = {"ABC%d" % n: "".join(sorted(v)) for n, v in sorted(abc.items()) if n >= max(abc) - 11}
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--json")
    ap.add_argument("--refresh", action="store_true")
    args = ap.parse_args()

    cf = cf_stats(args.refresh)
    at = at_stats()
    res = {"cf": cf, "at": at, "pulled_at": time.strftime("%Y-%m-%d %H:%M")}

    if args.json:
        json.dump(res, open(args.json, "w", encoding="utf-8"), ensure_ascii=False, indent=1)

    line = "=" * 70
    print(line)
    print(f"抓取时间 {res['pulled_at']}")
    print(line)
    print(f"CF  rating {cf['rating']}（最高 {cf['max_rating']}，{cf['rank']}）· {cf['contests']} 场 rated")
    print(f"    {cf['subs']} 条提交 / {cf['ok']} OK / {cf['ac']} 道 AC 题")
    print(f"    一次 AC {cf['one_ac']}/{cf['ac']} = {cf['one_ac'] / cf['ac']:.1%}")
    print(f"    ≥1400 {cf['ge1400']} 道（{cf['ge1400'] / cf['rated_ac']:.1%}）· ≥1500 {cf['ge1500']} 道")
    print("    难度分布: " + "  ".join(f"{k}:{v}" for k, v in cf["buckets"].items()))
    print("    判题结果: " + "  ".join(f"{k}:{v}" for k, v in cf["verdicts"].items()))
    print("    标签前 12: " + " · ".join(f"{t} {c}" for t, c in cf["tags"]))
    print("    近 8 场:")
    for c in cf["last_contests"]:
        print(f"      {c['date']}  {c['old']} → {c['new']}  rank {c['rank']}  {c['name'][:52]}")
    print("    月度:")
    for m, d in cf["monthly"].items():
        print(f"      {m}  新 AC {d['ac']:3d}  一次过 {d['one']:3d}（{d['one'] / d['ac']:.0%}）  ≥1400 {d['ge1400']}")
    print()
    print(f"AT  {at['rating']}（最高 {at['max_rating']}）· {at['contests']} 场（{at['rated']} rated）")
    print(f"    {at['subs']} 条提交 / {at['ac']} 道 AC；题位 " + " ".join(f"{k}{v}" for k, v in at["pos"].items()))
    print("    近 5 场:")
    for name, old, new, perf in at["last5"]:
        print(f"      {old} → {new}  perf {perf}  {str(name)[:56]}")
    print("    近 12 场 ABC 题位: " + "  ".join(f"{k} {v}" for k, v in at["recent_abc"].items()))
    print()
    print("洛谷：接口需登录（302），请手动填 ELO / 通过数。")


if __name__ == "__main__":
    main()
