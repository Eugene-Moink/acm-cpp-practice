/*
 * 中国剩余定理（CRT / exCRT）
 *
 * 【用途】
 *   求解同余方程组 x ≡ r[i] (mod m[i]), i = 0..n-1 的最小非负解。
 *   两两互质时可用互质版（逆元合并）；模数不互质时用扩展 CRT（exgcd 合并）。
 *
 * 【输入】
 *   r：余数数组，约定 x ≡ r[i] (mod m[i])，即第 i 个方程的余数是 r[i]、模数是 m[i]。
 *   m：模数数组，要求 m[i] >= 1（m[i] == 1 时该方程恒成立，等价于没有约束）。
 *
 * 【输出】
 *   互质版 crt：返回最小非负解（取模前先规整到 [0, M)）；若逆元不存在返回 -1。
 *   扩展版 excrt：成功返回 true，res 为最小非负解，lcm_out 为所有模数的 lcm；
 *                 无解返回 false，此时 res / lcm_out 的值无意义。
 *
 * 【复杂度】
 *   互质版 O(n log M)，扩展版 O(n log M)，M 为模数 lcm；空间 O(1)（不含输入数组）。
 *
 * 【易错提醒】
 *   1. 约定式子是 x ≡ r[i] (mod m[i])：第一个参数是余数、第二个参数是模数，别把 r 和 m 传反。
 *   2. 无解判定：合并时 (r2 - r1) 不能被 gcd(m1, m2) 整除就无解，扩展版必须返回 false；
 *      互质版中若某个 m[i] 的逆元不存在（如 m[i] == 1 或模数不互质），直接返回 -1。
 *   3. 中间乘法一定要用 __int128 防溢出：m1 与 k 相乘、m1 与 m2 相乘都可能达到 1e18 量级。
 *   4. 余数要规整到 [0, m)：C++ 的 % 对负数返回负数，合并中的 (r2 - r1) % m2 必须再 +m2 修正。
 *   5. 传入前建议先把 r[i] 规整到 [0, m[i])，否则解仍然正确但中间量会变大。
 */

const ll INF = 1e18;
const int MOD = 998244353;

bool crt_exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a >= 0;
    }

    ll g = crt_exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g >= 0;
}

ll crt_inv(ll a, ll mod)
{
    ll x = 0, y = 0;
    crt_exgcd(a, mod, x, y);
    if (mod < 0)
        mod = -mod;
    if (mod == 0)
        return 0;
    x %= mod;
    if (x < 0)
        x += mod;
    return x;
}

/* ==================== 互质版 CRT（模数两两互质） ==================== */

ll crt(const vector<ll> &r, const vector<ll> &m)
{
    int n = (int)r.size();
    if (n == 0)
        return 0;

    ll res = 0;
    ll mod = 1;

    for (int i = 0; i < n; i++)
    {
        ll mi = m[i];
        ll ri = r[i] % mi;
        if (ri < 0)
            ri += mi;

        ll t = (ri - res) % mi;
        if (t < 0)
            t += mi;

        ll x0 = 0, y0 = 0;
        ll g = crt_exgcd(mod, mi, x0, y0);
        if (g <= 0 || t % g != 0)
            return -1;

        ll inv = crt_inv(mod / g, mi / g);
        ll k = (t / g) % (mi / g);
        res = res + mod * k;
        mod = mod / g * mi;
        res %= mod;
        if (res < 0)
            res += mod;
    }

    return res % mod;
}

/* ==================== 扩展 CRT（模数不必互质，两两合并） ==================== */

bool excrt(const vector<ll> &r, const vector<ll> &m, ll &res, ll &lcm_out)
{
    int n = (int)r.size();
    res = 0;
    lcm_out = 1;
    if (n == 0)
        return true;

    ll rem = 0;
    ll lcm = 1;

    for (int i = 0; i < n; i++)
    {
        ll mi = m[i];
        ll ri = r[i] % mi;
        if (ri < 0)
            ri += mi;

        ll x = 0, y = 0;
        ll g = crt_exgcd(lcm, mi, x, y);
        if (g < 0)
        {
            g = -g;
            x = -x;
            y = -y;
        }
        if (g == 0)
        {
            res = 0;
            lcm_out = 0;
            return false;
        }

        ll diff = ri - rem;
        if (diff % g != 0)
        {
            res = 0;
            lcm_out = 0;
            return false;
        }

        ll mod2 = mi / g;
        ll k = (ll)((__int128)(diff / g) % mod2 * x % mod2);
        k %= mod2;
        if (k < 0)
            k += mod2;

        rem = rem + (ll)((__int128)lcm * k);
        lcm = (ll)((__int128)lcm / g * mi);

        rem %= lcm;
        if (rem < 0)
            rem += lcm;
    }

    res = rem;
    lcm_out = lcm;
    return true;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;

    vector<ll> r(n), m(n);
    for (int i = 0; i < n; i++)
        cin >> r[i] >> m[i];          // 读入 x ≡ r[i] (mod m[i])

    ll res = 0, lcm = 1;
    if (excrt(r, m, res, lcm))
        cout << res << " " << lcm << "\n";    // 最小非负解 与 模数 lcm
    else
        cout << "no solution\n";

    cout << crt(r, m) << "\n";        // 模数两两互质时用互质版；无逆元返回 -1
==================================================================== */
