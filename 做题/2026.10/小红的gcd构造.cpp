#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, int> fact(ll n)
{
    map<ll, int> res;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if (n > 1)
        res[n]++;

    return res;
}

void solve()
{
    ll x, y;
    cin >> x >> y;

    map<ll, int> fx = fact(x);
    map<ll, int> fy = fact(y);

    map<ll, int> total = fx;
    for (auto &p : fy)
    {
        total[p.first] += p.second;
    }

    ll g = 1;
    for (auto &p : total)
    {
        int e = p.second / 2;
        for (int i = 0; i < e; i++)
        {
            g *= p.first;
        }
    }

    ll a = g;
    ll b = x * y / g;

    cout << a << ' ' << b << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}