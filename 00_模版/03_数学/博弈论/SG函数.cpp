/* =====================================================
博弈论 SG 函数（Sprague-Grundy）

【用途】
  公平组合游戏（Nim 类）判断先手胜负。
【输入】
  n（状态上界）、k（可用移动量种数），接下来 k 个移动量。
【输出】
  sg[n] != 0 输出 Win，否则输出 Lose；多个独立游戏用 SG 值异或合并。
【复杂度】
  O(状态数 × 转移数)。
【易错提醒】
  1. 定理：SG 异或和 != 0 → 先手必胜；== 0 → 先手必败。
  2. sg[x] = mex({ sg[y] : x 能一步到 y })，mex 是最小的不在集合中的非负整数。
  3. sg[] 是定长全局数组（MAXN），n 不能超过 MAXN − 1。
  4. 多个独立子游戏要分别求 SG 再异或，不能把状态相加。
  5. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */

const int MAXN = 1005;

int sg[MAXN];

void calc_sg(int n, const vector<int> &move)
{
    for (int x = 0; x <= n; x++)
    {
        set<int> reachable;
        for (int mv : move)
        {
            if (x >= mv)
                reachable.insert(sg[x - mv]);
        }

        int g = 0;
        while (reachable.count(g))
            g++;
        sg[x] = g;
    }
}

void solve()
{
    int n, k;
    if (!(cin >> n >> k))
        return;

    vector<int> move(k);
    for (int i = 0; i < k; i++)
        cin >> move[i];

    calc_sg(n, move);

    cout << (sg[n] != 0 ? "Win" : "Lose") << "\n";
}
