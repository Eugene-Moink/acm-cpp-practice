/* =====================================================
逆元三种求法

【用途】
  求模意义下的乘法逆元，三种写法按适用场景选择。
【输入】
  inv_fermat(a) / inv_exgcd(a, mod) / init_inv()。
【输出】
  ll，a 在模 MOD（或 mod）下的逆元。
【复杂度】
  费马小定理 / exgcd：O(log MOD)；线性递推：预处理 O(n)。
【易错提醒】
  1. 费马小定理要求 MOD 为素数；exgcd 只要求 gcd(a, mod) = 1。
  2. 线性递推要求 MOD 为素数且 MOD > MAXN。
  3. 本文件自带 qpow 与 exgcd，与其它模板同时粘贴会重复定义。
  4. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */

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