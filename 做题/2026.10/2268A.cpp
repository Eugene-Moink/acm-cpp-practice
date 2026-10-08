#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll ans = 0;

    if (2 * k <= n)
    {
        for (int i = k; i <= n - k + 1; i++)
            ans += a[i];

        for (int i = 1; i <= k - 1; i++)
            ans += max(a[i], a[n - i + 1]);
    }
    else
    {
        for (int i = 1; i <= n - k + 1; i++)
            ans += max(a[i], a[n - i + 1]);
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
        solve();

    return 0;
}