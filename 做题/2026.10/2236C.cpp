#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b, x;
    cin >> a >> b >> x;

    if (a > b)
        swap(a, b);
    ll ans = abs(a - b);
    ll cnt = 0;

    while (b > 0)
    {
        b /= x;
        cnt++;
        if (a > b)
            swap(a, b);

        ans = min(ans, b - a + cnt);
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