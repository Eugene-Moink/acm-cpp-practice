/*
 * 欧拉函数 φ(n)
 *
 * 定义：φ(n) = [1, n] 中与 n 互质的数的个数
 *
 * 单点求法：O(sqrt(n))，质因数分解后套公式 φ(n) = n * Π(1 - 1/p)
 * 筛法求法：O(n)，用欧拉筛顺带求 [1, n] 的所有 φ
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */
const int MAXN = 1000005;

vector<int> primes;
bool is_prime[MAXN];
int phi[MAXN];

void sieve_phi(int n)
{
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;
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