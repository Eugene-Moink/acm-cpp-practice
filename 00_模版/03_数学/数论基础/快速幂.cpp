/* =====================================================
快速幂

【用途】
  求 base^exp mod mod；也是费马小定理求逆元的基础。
【输入】
  base, exp, mod (ll)。
【输出】
  ll，base^exp % mod。
【复杂度】
  O(log exp)。
【易错提醒】
  1. base 必须先取模，res 初始化为 1 % mod（mod == 1 时结果才是 0）。
  2. mod 接近 1e9 时 mod * mod 不会溢出 ll；更大时要用 __int128 或龟速乘。
  3. exp == 0 时返回 1 % mod。
  4. 用费马小定理求逆元时 mod 必须是素数。
===================================================== */
ll qpow(ll base, ll exp, ll mod)
{
    ll res = 1 % mod;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
