/*
 * 扩展欧几里得（exgcd）
 *
 * 输入：a, b (ll)
 * 输出：g, x, y 满足 ax + by = gcd(a, b)
 * 复杂度：O(log min(a, b))
 *
 * 用途：求逆元、解同余方程 ax ≡ b (mod m)、解不定方程 ax + by = c
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

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