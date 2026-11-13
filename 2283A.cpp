#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void solve()
{
    ll l, r;
    cin >> l >> r;
    int cnt = 0;
    while (l < r)
    {
        ll sum = (l + r) * (r - l + 1) / 2;
        if (sum >= l && sum <= r)
            break;
        if (sum > r)
            r--;
        else if (sum < l)
            l++;

        cnt++;
    }
    cout << cnt << '\n';
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