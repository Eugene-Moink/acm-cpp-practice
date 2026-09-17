#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    ll mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    ll target_mod = a[0] % k;
    for (int i = 1; i < n; i++)
    {
        if (a[i] % k != target_mod)
        {
            cout << "NO\n";
            return;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (mx - a[i]) / k;
    }

    cout << "YES " << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}