/*
 * 逆元三种求法
 *
 * 1. 费马小定理：inv(a) = a^(MOD-2) % MOD，要求 MOD 为素数
 * 2. 扩展欧几里得：inv(a) 满足 a*x ≡ 1 (mod m)，要求 gcd(a, m) = 1
 * 3. 线性递推：inv[i] = (MOD - MOD/i) * inv[MOD%i] % MOD，求 [1, n] 所有逆元
 *
 * 复杂度：
 *   费马小定理 / exgcd：O(log MOD)
 *   线性递推：预处理 O(n)
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

const ll MOD = 998244353;
const int MAXN = 200005;

ll inv_arr[MAXN];

ll qpow(ll base, ll exp, ll mod)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

// 方法一：费马小定理（MOD 必须为素数）
ll inv_fermat(ll a)
{
    return qpow(a, MOD - 2, MOD);
}

// 方法二：扩展欧几里得（MOD 任意，要求 gcd(a, MOD) = 1）
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

ll inv_exgcd(ll a, ll mod)
{
    ll x, y;
    exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

// 方法三：线性递推（预处理 [1, MAXN-1] 的所有逆元）
void init_inv()
{
    inv_arr[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        inv_arr[i] = (MOD - MOD / i) * inv_arr[MOD % i] % MOD;
    }
}

void solve()
{
    ll a;
    if (!(cin >> a))
        return;

    cout << inv_fermat(a) << "\n";
}