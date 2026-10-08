/* =====================================================
扩展欧几里得（exgcd）

【用途】
  求 ax + by = gcd(a, b) 的一组解，用于求逆元、解同余方程与不定方程。
【输入】
  a, b (ll)；x / y 为引用传出参数。
【输出】
  返回 gcd(a, b)，同时 x、y 满足 ax + by = gcd(a, b)。
【复杂度】
  O(log min(a, b))。
【易错提醒】
  1. x 可能为负，求逆元时要写 (x % mod + mod) % mod。
  2. a 与 mod 不互质时没有逆元，需要先判 gcd。
  3. 解 ax + by = c 要求 c % gcd(a, b) == 0，否则无解。
  4. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */

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