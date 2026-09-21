#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> memo;

ll g(ll x)
{
    ll sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

ll f(ll n)
{
    if (n <= 5)
        return n * n + 2 * n + 1;

    if (memo.count(n))
        return memo[n];

    ll ans = g(f(n / 2) * f(n / 2)) + g(f(n / 5));
    return memo[n] = ans;
}

void solve()
{
    ll n;

    while (cin >> n)
    {
        memo.clear();
        cout << f(n) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}