#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    int ans = 0;

    for (ll x = 1; 1LL * x * x <= a; x++)
    {
        if (a % x == 0)
        {

            ll remain1 = c - a / x;
            if (remain1 > 0 && remain1 % b == 0)
                ans++;

            ll x2 = a / x;
            if (x2 != x)
            {
                ll remain2 = c - a / x2;
                if (remain2 > 0 && remain2 % b == 0)
                    ans++;
            }
        }
    }

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