#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m;
    cin >> n >> m;

    ll min_double = LLONG_MAX;
    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[i] = x;
        min_double = min(min_double, x + y);
    }

    sort(a.begin(), a.end());

    ll ans = 0, cost = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i > 0)
            cost += a[i - 1];
        if (cost > m)
            break;

        ll remian = m - cost;
        ll cur = i + 2 * (remian / min_double);
        ans = max(cur, ans);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}