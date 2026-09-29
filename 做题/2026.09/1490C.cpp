#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x;
    cin >> x;
    ll n = round(cbrt(x));
    for (ll a = 1; a <= n; a++)
    {
        ll rest = x - a * a * a;
        ll b = round(cbrt(rest));
        for (ll cand = max(1LL, b - 2); cand <= b + 2; cand++)
        {
            if (cand * cand * cand == rest)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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