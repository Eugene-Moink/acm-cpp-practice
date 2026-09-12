#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, x, y, z;
    cin >> n >> x >> y >> z;

    ll time_no_ai = (n + x + y - 1) / (x + y);

    ll time_with_ai = z;
    ll written_by_maxim = z * x;

    if (written_by_maxim < n)
    {
        ll remaining = n - written_by_maxim;
        ll new_speed = x + 10 * y;
        time_with_ai += (remaining + new_speed - 1) / new_speed;
    }

    cout << min(time_no_ai, time_with_ai) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}