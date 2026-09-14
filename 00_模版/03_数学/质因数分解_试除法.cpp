/*
 * 质因数分解（试除法）
 *
 * 输入：n (ll)，要求 n >= 2
 * 输出：vector<ll>，n 的所有质因子（升序，含重复）
 * 复杂度：O(sqrt(n))
 *
 * 防溢出：循环条件用 i <= n / i，不要用 i * i <= n
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */
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
