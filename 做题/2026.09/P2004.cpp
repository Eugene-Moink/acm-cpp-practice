#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, c;
    cin >> n >> m >> c;

    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid)
        for (int &x : row)
            cin >> x;

    vector<vector<ll>> pref(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i - 1][j - 1];

    ll max_sum = LLONG_MIN;
    int ansX = 0, ansY = 0;

    for (int i = 0; i <= n - c; i++)
    {
        for (int j = 0; j <= m - c; j++)
        {
            ll sum = pref[i + c][j + c] - pref[i][j + c] - pref[i + c][j] + pref[i][j];
            if (sum > max_sum)
            {
                max_sum = sum;
                ansX = i + 1;
                ansY = j + 1;
            }
        }
    }

    cout << ansX << ' ' << ansY << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}