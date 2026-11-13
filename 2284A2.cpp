#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a[i] = 1LL << x;
    }

    sort(a.begin(), a.end(), greater<ll>());

    ll X = 0, Y = 0;

    for (ll x : a)
    {
        if (X <= Y)
            X += x;
        else
            Y += x;
    }

    cout << X * Y << '\n';
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