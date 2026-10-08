#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll o, x, p;
    cin >> o >> x >> p;

    ll ans = 0;
    ll o, x, p;
    cin >> o >> x >> p;

    ll ans = 0;
    if (o == 1)
        ans = (x << p) & 0xFFF;
    else if (o == 2)
        ans = (x >> p) | (((1 << p) - 1) << (12 - p));
    else if (o == 3)
        ans = x & ~(1 << p);
    else if (o == 4)
        ans = x | (1 << p);

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