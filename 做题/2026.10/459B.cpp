#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    ll mx = -1, mn = 1e9 + 5;
    ll cnt_mx = 0, cnt_mn = 0;

    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;

        if (x > mx)
        {
            mx = x;
            cnt_mx = 1;
        }
        else if (x == mx)
        {
            cnt_mx++;
        }

        if (x < mn)
        {
            mn = x;
            cnt_mn = 1;
        }
        else if (x == mn)
        {
            cnt_mn++;
        }
    }

    ll ans = 0;
    if (mx != mn)
        ans = cnt_mn * cnt_mx;
    else
        ans = 1LL * n * (n - 1) / 2;

    cout << mx - mn << ' ' << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}