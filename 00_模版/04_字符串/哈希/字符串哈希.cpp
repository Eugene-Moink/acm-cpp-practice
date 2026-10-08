/* =====================================================
字符串哈希（单哈希）

【用途】
  O(1) 判断两个子串是否相等、求最长公共前缀等。
【输入】
  init_hash(s) 预处理；get_hash(l, r) 查询子串哈希（0-based 闭区间）。
【输出】
  ll，子串的哈希值。
【复杂度】
  预处理 O(N)，单次查询 O(1)。
【易错提醒】
  1. 原理：h[i] = h[i-1] * base + s[i]；子串 [l, r] 的哈希 = h[r+1] − h[l] * pw[r−l+1]。
  2. 相减后要 +MOD 再 %MOD，否则负数取模结果会错。
  3. base 取 131 或 13331，MOD 用大素数；单哈希可能被卡，关键题用双哈希。
  4. h / pw 是定长数组，字符串更长时要同步调大 MAXN。
  5. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */

const ll BASE = 131;
const ll MOD = 998244353;
const int MAXN = 1000005;

ll h[MAXN];
ll pw[MAXN];

void init_hash(const string &s)
{
    int n = s.size();
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * BASE % MOD;

    h[0] = 0;
    for (int i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] * BASE + s[i]) % MOD;
    }
}

ll get_hash(int l, int r)
{
    return (h[r + 1] - h[l] * pw[r - l + 1] % MOD + MOD) % MOD;
}

void solve()
{
    string s;
    if (!(cin >> s))
        return;

    init_hash(s);

    int q;
    cin >> q;
    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get_hash(l1, r1) == get_hash(l2, r2))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
