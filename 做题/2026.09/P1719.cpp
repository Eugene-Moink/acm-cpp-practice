#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    int ans = INT_MIN;

    for (int top = 0; top < n; ++top)
    {
        vector<int> colSum(n, 0);

        for (int bottom = top; bottom < n; ++bottom)
        {
            for (int j = 0; j < n; ++j)
            {
                colSum[j] += grid[bottom][j];
            }

            int cur = 0, best = INT_MIN;
            for (int j = 0; j < n; ++j)
            {
                cur = max(colSum[j], cur + colSum[j]);
                best = max(best, cur);
            }
            ans = max(ans, best);
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