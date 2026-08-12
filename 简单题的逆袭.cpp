#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll x, y;
    cin >> x >> y;

    if (x == 0 || x == 1)
    {
        cout << -1 << '\n';
        return;
    }
    if (y == 0)
    {
        cout << -1 << '\n';
        return;
    }
    if (x > y)
    {
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;
    while (y >= x)
    {
        y /= x;
        ans++;
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
        moink();
    }
    return 0;
}