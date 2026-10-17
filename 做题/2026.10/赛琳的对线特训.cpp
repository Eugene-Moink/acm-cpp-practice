#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    ll k;
    cin >> n >> k;

    ll mx = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
        if (sum + mx >= k)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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