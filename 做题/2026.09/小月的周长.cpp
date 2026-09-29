#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<bool>> seen(n, vector<bool>(m, 1));
    x = x - 1;
    y = y - 1;
    for (int j = 0; j < m; j++)
        seen[x][j] = false;
    for (int i = 0; i < n; i++)
        seen[i][y] = false;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (seen[i][j])
            {
                if (i == 0 || !seen[i - 1][j])
                    ans++;
                if (i == n - 1 || !seen[i + 1][j])
                    ans++;

                if (j == 0 || !seen[i][j - 1])
                    ans++;
                if (j == m - 1 || !seen[i][j + 1])
                    ans++;
            }
        }
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
    {
        solve();
    }
    return 0;
}