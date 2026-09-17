/*
 * 字符串哈希（单哈希）
 *
 * 用途：O(1) 判断子串是否相等、求最长公共前缀等
 * 复杂度：预处理 O(N)，查询 O(1)
 *
 * 原理：把字符串映射为一个整数，h[i] = h[i-1] * base + s[i]
 *       子串 [l, r] 的哈希 = h[r+1] - h[l] * pow_base[r-l+1]
 *
 * 注意：base 和 MOD 越大越好，建议 base 取 131 或 13331
 *       为防止被卡，建议使用双哈希（两个 MOD）
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

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
