/*
 * 容斥原理（Inclusion-Exclusion）
 *
 * 【用途】
 *   把「至少满足一个条件」的并集大小拆成子集交的大小加减；
 *   常用场景：能被若干数中至少一个整除的个数、与 k 互质的个数、
 *   错排计数、多重集排列数。
 *
 * 【输入】
 *   n：条件个数 / 元素个数；k：给出的整数（可为负，内部取绝对值）。
 *   primes：若干互不相同的素数；cnt：各部分重数，满足 sum(cnt) == n。
 *
 * 【输出】
 *   inclusion_exclusion 类骨架：并集大小（long long）。
 *   与 k 互质的个数、至少被一个素数整除的个数：个数（long long）。
 *   错排 derange：长度为 n 的排列中相邻位置均不相等的方案数（取模）。
 *   多重集排列 multiset_perm：n! / (c1! c2! ...)（取模）。
 *
 * 【复杂度】
 *   二进制枚举容斥 O(2^n)；互质/整除应用 O(sqrt(k) + 2^w)（w 为不同素因子个数）；
 *   错排 O(n)；多重集排列预处理阶乘 O(MAXN)，每次查询 O(不同种类数)。
 *
 * 【易错提醒】
 *   1. 容斥符号是 (-1)^(popcount+1)：奇数个条件取加号，偶数个取减号；
 *      写成 __builtin_popcount(mask) & 1 ? add : sub 即可。
 *   2. 枚举起点必须是 mask = 1，空集（mask = 0）不能计入，否则答案会多算一次全集。
 *   3. 枚举范围写 (1 << n) 时 n 不能超过 20 左右，否则 2^n 会超时；n 更大要换其它做法。
 *   4. 与 k 互质的个数用「总个数 - 与 k 不互质的个数」，注意 k <= 1 时要特判（结果恒为 n）。
 *   5. 错排递推是 D[n] = (n-1) * (D[n-1] + D[n-2])，初值 D[0] = 1、D[1] = 0。
 *   6. 多重集排列要乘的是每个 cnt[i]! 的逆元，别乘成正向阶乘。
 */

const ll INF = 1e18;
const int MOD = 998244353;

/* ==================== 容斥骨架：二进制枚举 ==================== */

ll inclusion_exclusion_count(const vector<ll> &cnt)
{
    int n = (int)cnt.size();
    ll res = 0;

    for (int mask = 1; mask < (1 << n); ++mask)
    {
        ll inter = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                inter += cnt[i];
        }

        if (__builtin_popcount((unsigned)mask) & 1)
            res += inter;
        else
            res -= inter;
    }

    return res;
}

/* ==================== 应用一：与 k 互质 / 至少被一个素数整除 ==================== */

vector<ll> distinct_prime_factors(ll k)
{
    vector<ll> p;
    if (k < 0)
        k = -k;

    for (ll d = 2; d * d <= k; d++)
    {
        if (k % d == 0)
        {
            p.push_back(d);
            while (k % d == 0)
                k /= d;
        }
    }

    if (k > 1)
        p.push_back(k);

    return p;
}

ll count_coprime(ll n, ll k)
{
    if (k < 0)
        k = -k;
    if (n <= 0)
        return 0;
    if (k <= 1)
        return n;

    vector<ll> p = distinct_prime_factors(k);
    int w = (int)p.size();
    ll bad = 0;

    for (int mask = 1; mask < (1 << w); ++mask)
    {
        ll prod = 1;
        for (int i = 0; i < w; i++)
        {
            if (mask & (1 << i))
                prod *= p[i];
        }

        if (__builtin_popcount((unsigned)mask) & 1)
            bad += n / prod;
        else
            bad -= n / prod;
    }

    return n - bad;
}

ll count_divisible_by_any(ll n, const vector<ll> &primes)
{
    if (n <= 0)
        return 0;

    int w = (int)primes.size();
    ll res = 0;

    for (int mask = 1; mask < (1 << w); ++mask)
    {
        ll prod = 1;
        for (int i = 0; i < w; i++)
        {
            if (mask & (1 << i))
                prod *= primes[i];
        }

        if (__builtin_popcount((unsigned)mask) & 1)
            res += n / prod;
        else
            res -= n / prod;
    }

    return res;
}

/* ==================== 应用二：错排数 D[n] ==================== */

ll derange(int n)
{
    if (n <= 0)
        return 1;
    if (n == 1)
        return 0;

    ll d0 = 1;
    ll d1 = 0;

    for (int i = 2; i <= n; i++)
    {
        ll d2 = (ll)(i - 1) % MOD * ((d1 + d0) % MOD) % MOD;
        d0 = d1;
        d1 = d2;
    }

    return d1;
}

/* ==================== 应用三：多重集排列数 n! / (c1! c2! ...) ==================== */

const int MAXN = 200005;

ll iec_fact[MAXN];
ll iec_inv_fact[MAXN];

ll iec_qpow(ll base, ll exp)
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

void iec_init_fact()
{
    iec_fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        iec_fact[i] = iec_fact[i - 1] * i % MOD;
    }

    iec_inv_fact[MAXN - 1] = iec_qpow(iec_fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
    {
        iec_inv_fact[i] = iec_inv_fact[i + 1] * (i + 1) % MOD;
    }
}

ll multiset_perm(const vector<int> &cnt)
{
    ll n = 0;
    for (int c : cnt)
        n += c;

    ll res = iec_fact[n];
    for (int c : cnt)
    {
        res = res * iec_inv_fact[c] % MOD;
    }

    return res;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    iec_init_fact();                  // 求多重集排列前必须先调用一次

    ll n, k;
    cin >> n >> k;
    cout << count_coprime(n, k) << "\n";     // [1, n] 中与 k 互质的个数

    int w;
    cin >> w;
    vector<ll> primes(w);
    for (int i = 0; i < w; i++)
        cin >> primes[i];
    cout << count_divisible_by_any(n, primes) << "\n";   // 至少被一个素数整除的个数

    int q;
    cin >> q;
    cout << derange(q) << "\n";              // 错排数 D[q]

    int kind;
    cin >> kind;
    vector<int> cnt(kind);
    int total = 0;
    for (int i = 0; i < kind; i++)
    {
        cin >> cnt[i];
        total += cnt[i];
    }
    cout << multiset_perm(cnt) << "\n";      // == total! / (c1! c2! ...)
==================================================================== */
