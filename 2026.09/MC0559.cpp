#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> a;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }

    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++)
    {
        ll x = a[i].first, y = a[i].second;
        ll tmp = 0;
        for (auto &p : a)
        {
            ll dist = abs(x - p.first) + abs(y - p.second);
            tmp = max(tmp, dist);
        }
        ans = min(ans, tmp);
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