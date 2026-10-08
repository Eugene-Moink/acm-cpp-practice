#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x, y;
    cin >> x >> y;

    ll ans = LLONG_MAX;

    for (int k = 0; k <= 63; k++)
    {
        ll v = x >> k;
        if ((v & y) == v)
        {
            if (v == y)
                ans = min(ans, (ll)k);
            else
                ans = min(ans, (ll)k + 1);
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}