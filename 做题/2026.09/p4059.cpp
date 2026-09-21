#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int id(char c)
{
    if (c == 'A')
        return 0;
    if (c == 'T')
        return 1;
    if (c == 'G')
        return 2;
    return 3;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    int d[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> d[i][j];

    int A, B;
    cin >> A >> B;

    const int INF = 1e9;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(3, -INF)));

    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0][2] = dp[i - 1][0][0] - A;
        if (i > 1)
            dp[i][0][2] = max(dp[i][0][2], dp[i - 1][0][2] - B);
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j][1] = dp[0][j - 1][0] - A;
        if (j > 1)
            dp[0][j][1] = max(dp[0][j][1], dp[0][j - 1][1] - B);
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                continue;

            if (i > 0 && j > 0)
            {
                int best = max({dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]});
                if (best != -INF)
                    dp[i][j][0] = max(dp[i][j][0], best + d[id(s1[i - 1])][id(s2[j - 1])]);
            }

            if (j > 0)
            {
                if (dp[i][j - 1][0] != -INF)
                    dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - A);
                if (dp[i][j - 1][1] != -INF)
                    dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1] - B);
            }

            if (i > 0)
            {
                if (dp[i - 1][j][0] != -INF)
                    dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][0] - A);
                if (dp[i - 1][j][2] != -INF)
                    dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][2] - B);
            }
        }
    }

    cout << max({dp[n][m][0], dp[n][m][1], dp[n][m][2]}) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}