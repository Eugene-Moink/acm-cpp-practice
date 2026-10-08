/* =====================================================
质因数分解（试除法）

【用途】
  把 n 分解为质因子的乘积。
【输入】
  n (ll)，要求 n >= 2。
【输出】
  vector<ll>，n 的全部质因子，升序且含重复（例如 12 -> 2, 2, 3）。
【复杂度】
  O(√n)。
【易错提醒】
  1. 防溢出：循环条件用 i <= n / i，不要写 i * i <= n。
  2. 返回值含重复因子；要去重或要指数请改用 map<ll, int>。
  3. n < 2 时返回空表，调用方需要自己特判。
  4. n 是大素数时循环会一直跑到 √n，单次分解 1e18 附近的数会偏慢。
===================================================== */
vector<ll> get_prime_factors(ll n)
{
    vector<ll> factors;
    for (ll i = 2; i <= n / i; i++)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        factors.push_back(n);
    }
    return factors;
}

void solve()
{
    ll n;
    if (!(cin >> n))
        return;

    vector<ll> ans = get_prime_factors(n);

    for (ll x : ans)
    {
        cout << x << "\n";
    }
}
