/* =====================================================
组合数预处理（阶乘 + 逆元阶乘）

【用途】
  多次求组合数 C(n, m)、排列数 A(n, m) 对素数 MOD 取模。
【输入】
  init_comb() 无参数，规模由全局 MAXN 决定；查询为 n, m (int)。
【输出】
  ll，组合数 / 排列数；m 越界时返回 0。
【复杂度】
  预处理 O(MAXN)，单次查询 O(1)。
【易错提醒】
  1. init_comb() 必须在处理查询前调用一次。
  2. MOD 必须是素数，否则费马小定理求逆元不成立。
  3. MAXN 要大于题目中最大的 n，否则数组越界。
  4. 本文件 MOD 是 int，矩阵快速幂等模板是 ll，混用时注意统一类型。
===================================================== */
const int MOD = 998244353;
const int MAXN = 200005;

ll fact[MAXN];
ll inv_fact[MAXN];

ll qpow(ll base, ll exp)
{
    ll res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void init_comb()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv_fact[MAXN - 1] = qpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
    {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

ll C(int n, int m)
{
    if (m < 0 || m > n)
        return 0;
    return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
}

ll A(int n, int m)
{
    if (m < 0 || m > n)
        return 0;
    return fact[n] * inv_fact[n - m] % MOD;
}

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    cout << C(n, m) << "\n";
}

// init_comb() 必须在处理查询前调用一次