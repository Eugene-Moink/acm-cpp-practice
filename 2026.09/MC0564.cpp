#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    while (n--)
    {
        ll x;
        cin >> x;
        ll low = (15 & x) << 4;
        ll high = x >> 4;
        ll tmp = low | high;

        ans += tmp;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}