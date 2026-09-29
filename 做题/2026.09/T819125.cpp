#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> is_prime;
vector<int> prime;

void sieve(int n)
{
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    prime.clear();

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            prime.push_back(i);

        for (int j = 0; j < (int)prime.size() && 1LL * i * prime[j] <= n; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void solve()
{
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i + 1 < (int)s.size(); i++)
    {
        string t = s.substr(i, 2);
        int num = stoi(t);

        if (is_prime[num])
            ans += num;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(100);

    solve();
    return 0;
}