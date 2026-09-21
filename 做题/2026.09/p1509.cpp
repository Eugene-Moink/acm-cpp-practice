#include <bits/stdc++.h>
using namespace std;

pair<int, int> dp[105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> rmb(n), rp(n), tim(n);
    for (int i = 0; i < n; i++)
        cin >> rmb[i] >> rp[i] >> tim[i];

    int m, r;
    cin >> m >> r;

    for (int k = 0; k < n; k++)
    {
        for (int i = m; i >= rmb[k]; i--)
        {
            for (int j = r; j >= rp[k]; j--)
            {
                pair<int, int> prev = dp[i - rmb[k]][j - rp[k]];
                pair<int, int> cand = {prev.first + 1, prev.second + tim[k]};

                if (cand.first > dp[i][j].first ||
                    (cand.first == dp[i][j].first && cand.second < dp[i][j].second))
                {
                    dp[i][j] = cand;
                }
            }
        }
    }

    int maxCnt = 0, minTime = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= r; j++)
        {
            if (dp[i][j].first > maxCnt)
            {
                maxCnt = dp[i][j].first;
                minTime = dp[i][j].second;
            }
            else if (dp[i][j].first == maxCnt && dp[i][j].second < minTime)
            {
                minTime = dp[i][j].second;
            }
        }
    }

    cout << minTime << '\n';
    return 0;
}