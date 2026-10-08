/* =====================================================
因数枚举（试除法）模板

【用途】
  1. get_divisors(n)：返回 n 的全部正因数（升序）。
  2. has_divisor_at_most(n, k)：判断 n 是否存在 <= k 的正因数。

【输入】
  get_divisors：正整数 n (ll)。
  has_divisor_at_most：正整数 n (ll)、上界 k (ll)。

【输出】
  get_divisors：vector<ll>，n 的全部正因数，升序排列（含 1 和 n）。
  has_divisor_at_most：bool，存在返回 true。

【复杂度】
  get_divisors：O(√n)，因数个数 O(√n)。
  has_divisor_at_most：O(min(k, √n))。

【易错提醒】
  1. 循环条件用 i <= n / i，绝对不要写 i * i <= n：n 接近 9.2e18 时 i * i 会溢出成负数，导致死循环。
  2. 成对枚举时必须判 i != n / i，否则完全平方数会把平方根压进两次。
  3. n == 1 时循环一次都不进，直接压入 1，返回 {1}。
  4. n <= 0 直接返回空数组，不要进入 while 或除零。
  5. 最后统一 sort：先 push 小因数、后 push 大因数，得到的顺序是「小半段升序 + 大半段降序」，不 sort 会错。
  6. 判断「是否存在 <= k 的因数」时，枚举到 min(k, n / i) 即可提前结束，不要白跑满 √n。
  7. 这里返回的是全部因数（可重复质因子请用质因数分解模板）；n 为 1e18 时因数个数最多约 1e5，注意别在循环里做 O(n) 操作。
===================================================== */

/* ==================== 一、枚举全部因数 ==================== */

vector<ll> get_divisors(ll n)
{
    vector<ll> divs;
    if (n <= 0)
        return divs;
    for (ll i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            divs.push_back(i);
            if (i != n / i)
                divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

/* ==================== 二、判断是否存在 <= k 的因数 ==================== */

bool has_divisor_at_most(ll n, ll k)
{
    if (n <= 0 || k <= 0)
        return false;
    for (ll i = 1; i <= k && i <= n / i; i++)
    {
        if (n % i == 0)
            return true;
    }
    return false;
}

bool has_divisor_at_least(ll n, ll k)
{
    if (n <= 0 || k <= 0 || k > n)
        return false;
    for (ll i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            if (i >= k || n / i >= k)
                return true;
        }
    }
    return false;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    ll n, k;
    cin >> n >> k;

    vector<ll> divs = get_divisors(n);
    cout << divs.size() << "\n";
    for (ll d : divs)
        cout << d << " ";
    cout << "\n";

    cout << has_divisor_at_most(n, k) << "\n";    // 是否存在 <= k 的因数
    cout << has_divisor_at_least(n, k) << "\n";   // 是否存在 >= k 的因数

    // n = 12  -> 1 2 3 4 6 12
    // n = 36  -> 1 2 3 4 6 9 12 18 36（完全平方数 6 只出现一次）
    // n = 1   -> 1
    // n = 12, k = 5 -> 1（因数 1 / 2 / 3 / 4 都 <= 5）
==================================================================== */
