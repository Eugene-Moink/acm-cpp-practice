#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    ll sum = 0, val = 0;
    for (int i = 0; i < m; i++)
    {
        sum += a[i];
        val += a[i] * (i + 1);
    }

    ll ans = val;
    for (int l = 0; l + m < n; l++)
    {
        val = val - sum + a[l + m] * m;
        sum = sum - a[l] + a[l + m];

        ans = max(ans, val);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}