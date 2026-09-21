#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 0)
                grid[i][j] = -1;
        }
    }

    vector<vector<ll>> pref(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i][j];
        }
    }

    ll ans = 0;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= m; y1++)
        {
            for (int x2 = x1; x2 <= n; x2++)
            {
                for (int y2 = y1; y2 <= m; y2++)
                {
                    ll sum = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
                    if (sum > 0)
                        ans++;
                }
            }
        }
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