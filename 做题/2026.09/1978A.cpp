#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    ll val_max = -1;
    for (int i = 0; i < n - 1; i++)
    {
        val_max = max(val_max, a[i]);
    }
    ll ans = val_max + a[n - 1];
    cout << ans << '\n';
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