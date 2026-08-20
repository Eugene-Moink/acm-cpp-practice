#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    ll a0;
    cin >> a0;
    for (int i = 1; i < n; ++i)
    {
        ll x;
        cin >> x;
    }
    ll b0;
    cin >> b0;
    for (int i = 1; i < m; ++i)
    {
        ll x;
        cin >> x;
    }

    ll bea = a0 + n;
    ll ver = b0 + m;

    cout << (bea >= ver ? 1 : 2) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}