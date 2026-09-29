#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    ll power = 100;

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;

        power -= min(x, 50LL);
        power = max(power, 100LL);

        power += y;
        power = min(power, 400LL);
    }

    cout << power << '\n';
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