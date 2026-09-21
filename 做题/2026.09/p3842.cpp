#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[20005][2];
ll l[20005], r[20005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];

    dp[1][0] = abs(1LL - r[1]) + (r[1] - l[1]);
    dp[1][1] = abs(1LL - l[1]) + (r[1] - l[1]);

    for (int i = 2; i <= n; ++i)
    {
        ll len = r[i] - l[i];
        dp[i][0] = min(dp[i - 1][0] + abs(l[i - 1] - r[i]),
                       dp[i - 1][1] + abs(r[i - 1] - r[i])) +
                   len + 1;
        dp[i][1] = min(dp[i - 1][0] + abs(l[i - 1] - l[i]),
                       dp[i - 1][1] + abs(r[i - 1] - l[i])) +
                   len + 1;
    }

    ll ans = min(dp[n][0] + abs(l[n] - (ll)n),
                 dp[n][1] + abs(r[n] - (ll)n));
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}