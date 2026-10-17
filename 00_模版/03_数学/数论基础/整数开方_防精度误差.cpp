/* =====================================================
整数开方_防精度误差

【用途】
  整数开平方 / 开立方 / 判完全平方数 / 判完全立方数，要求结果精确到整数，不允许浮点误差。
  典型：枚举因子时上界取 floor(sqrt(n))、判 a² + b² 类等式、n 的三次方根二分。
【输入】
  n：非负整数（ll）。
【输出】
  floor_sqrt(n)  返回最大的 r 使 r² ≤ n（n < 0 返回 -1）
  is_square(n)   判断 n 是否完全平方
  floor_cbrt(n)  返回最大的 r 使 r³ ≤ n
【复杂度】
  O(1)（初值 + 修正）/ O(log n)（纯二分），常数极小。
【易错提醒】
  1. (ll)sqrt(n) 在 n 接近 1e18 时会差 ±1，必须用 while 循环修正，不能直接用。
  2. r * r 可能溢出 ll：用 __int128 比较，或先判 r > n / r。
  3. 修正循环只会走 1~2 步，不要写成「从 1 开始 for」的 O(√n) 暴力。
  4. 负数、0 要单独特判（0 的平方根是 0，负数的整数根无意义）。
  5. 判 a² + b² = n 这类等式时，直接 `is_square(n - a*a)` 比 sqrt 更可靠。
===================================================== */
bool mul_le(ll a, ll b, ll lim)
{
    return (__int128)a * b <= (__int128)lim;
}

bool mul_eq(ll a, ll b, ll lim)
{
    return (__int128)a * b == (__int128)lim;
}

ll floor_sqrt(ll n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    ll r = (ll)sqrtl((long double)n);
    while (r > 0 && !mul_le(r, r, n))
    {
        r--;
    }
    while (mul_le(r + 1, r + 1, n))
    {
        r++;
    }
    return r;
}

bool is_square(ll n)
{
    if (n < 0)
    {
        return false;
    }
    ll r = floor_sqrt(n);
    return mul_eq(r, r, n);
}

ll floor_cbrt(ll n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    ll r = (ll)cbrtl((long double)n);
    while (r > 0 && !mul_le(r, r * r, n))
    {
        r--;
    }
    while (mul_le(r + 1, (r + 1) * (r + 1), n))
    {
        r++;
    }
    return r;
}

bool is_cube(ll n)
{
    if (n < 0)
    {
        return false;
    }
    ll r = floor_cbrt(n);
    return mul_eq(r, r * r, n);
}

/* ==================== 调用示例（贴进自己的 main） ====================
    ll n;
    cin >> n;

    cout << floor_sqrt(n) << "\n";                  // 整数平方根
    cout << (is_square(n) ? "yes" : "no") << "\n";   // 完全平方数
    cout << floor_cbrt(n) << "\n";                  // 整数立方根

    // 枚举因子到 sqrt：
    // for (ll d = 1; d <= floor_sqrt(n); d++)
    //     if (n % d == 0) { ... }
   ==================================================================== */
