#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2][1005];
const ll inf = -1e18;
void moink()
{
    int M, S, T;
    cin >> M >> S >> T;

    for (int m = 0; m <= 1000; m++)
    {
        dp[0][m] = inf;
    }
    dp[0][M] = 0;

    for (int t = 1; t <= T; ++t)
    {
        int cur = t & 1;
        int pre = cur ^ 1;
        for (int m = 0; m <= 1000; m++)
        {
            dp[cur][m] = inf;
        }

        for (int m = 0; m <= 1000; m++)
        {
            if (dp[pre][m] != inf)
                dp[cur][m] = max(dp[cur][m], dp[pre][m] + 17);

            if (m + 10 <= 1000 && dp[pre][m + 10] != inf)
                dp[cur][m] = max(dp[cur][m], dp[pre][m + 10] + 60);

            if (m >= 4 && dp[pre][m - 4] != inf)
                dp[cur][m] = max(dp[cur][m], dp[pre][m - 4]);
        }

        ll max_dist = 0;
        for (int m = 0; m <= 1000; m++)
        {
            max_dist = max(max_dist, dp[cur][m]);
        }

        if (max_dist > S)
        {
            cout << "Yes\n"
                 << t << '\n';
            return;
        }
    }

    int final = T & 1;
    ll ans = 0;
    for (int m = 0; m <= 1000; m++)
        ans = max(ans, dp[final][m]);

    cout << "No\n"
         << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}