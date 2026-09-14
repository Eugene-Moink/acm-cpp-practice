#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x;
    cin >> x;
    ll r = sqrt(x);
    while ((r + 1) <= x / (r + 1))
        r++;
    while (r * r > x)
        r--;

    cout << r << ' '
         << x - r * r << ' '
         << (r + 1) * (r + 1) - x << '\n';
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