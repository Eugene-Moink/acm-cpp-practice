#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
vector<int> primes;

void init()
{
    vector<bool> isPrime(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= MAXN; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            if (1LL * i * i <= MAXN)
            {
                for (long long j = 1LL * i * i; j <= MAXN; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    for (int x : a)
    {
        int p = *upper_bound(primes.begin(), primes.end(), x);
        cout << p << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}