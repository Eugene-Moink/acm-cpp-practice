#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    int x_min_val = INT_MAX, x_max_val = INT_MIN;
    int y_min_val = INT_MAX, y_max_val = INT_MIN;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        x_min_val = min(x, x_min_val);
        x_max_val = max(x, x_max_val);
        y_min_val = min(y, y_min_val);
        y_max_val = max(y, y_max_val);
    }

    ll ans = 1LL * (x_max_val - x_min_val) * (y_max_val - y_min_val);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}