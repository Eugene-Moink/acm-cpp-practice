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