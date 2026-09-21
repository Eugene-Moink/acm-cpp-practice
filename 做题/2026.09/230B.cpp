#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> is_prime;
vector<ll> prime;

void table(int n)
{
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime.push_back(i);

        for (int j = 0; j < prime.size() && 1LL * i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve()
{
    table(1000005);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
    {
        cin >> x;
    }

    for (ll x : a)
    {
        ll tmp = sqrt(x);
        if (tmp * tmp != x)
        {
            cout << "NO\n";
            continue;
        }
        else
        {
            if (is_prime[tmp])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}