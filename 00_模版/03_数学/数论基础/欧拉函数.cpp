/* =====================================================
欧拉函数 φ(n)

【用途】
  求 [1, n] 中与 n 互质的数的个数；也可一次筛出 [1, n] 的全部 φ 值。
【输入】
  n (ll) 用于单点求值；sieve_phi(n) 用于筛表。
【输出】
  ll（单点）；全局 phi[]、is_prime[]、primes[]。
【复杂度】
  单点 O(√n)；筛法 O(n)。
【易错提醒】
  1. 每轮 sieve_phi 会重置 primes，但 is_prime 与 phi 是定长全局数组，n 不能超过 MAXN - 1。
  2. φ(1) = 1，不要漏。
  3. 单点公式必须写成 res = res / p * (p - 1)（先整除后乘），浮点版本会丢精度。
  4. 需要多次单点查询时用筛表，不要反复调用 get_phi。
===================================================== */
const int MAXN = 1000005;

vector<int> primes;
bool is_prime[MAXN];
int phi[MAXN];

void sieve_phi(int n)
{
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
    primes.clear();
    phi[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < (int)primes.size() && 1LL * i * primes[j] <= n; j++)
        {
            int p = primes[j];
            is_prime[i * p] = false;
            if (i % p == 0)
            {
                phi[i * p] = phi[i] * p;
                break;
            }
            else
            {
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
}

ll get_phi(ll n)
{
    ll res = n;
    for (ll i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}

void solve()
{
    ll n;
    if (!(cin >> n))
        return;

    cout << get_phi(n) << "\n";
}
