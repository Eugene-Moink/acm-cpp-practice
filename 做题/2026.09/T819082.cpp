#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int H, W;
    cin >> H >> W;
    vector<vector<int>> grid(H, vector<int>(W));
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> grid[i][j];
        }
    }

    int total = 0;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (j + 1 < W && grid[i][j] == grid[i][j + 1])
            {
                total++;
            }

            if (i + 1 < H && grid[i][j] == grid[i + 1][j])
            {
                total++;
            }
        }
    }

    int ans = total;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int old_c = grid[i][j];
            for (int new_c = 1; new_c <= 3; new_c++)
            {
                if (old_c == new_c)
                    continue;

                int delta = 0;

                if (i > 0)
                {
                    if (grid[i - 1][j] == old_c)
                        delta--;
                    if (grid[i - 1][j] == new_c)
                        delta++;
                }

                if (i < H - 1)
                {
                    if (grid[i + 1][j] == old_c)
                        delta--;
                    if (grid[i + 1][j] == new_c)
                        delta++;
                }

                if (j > 0)
                {
                    if (grid[i][j - 1] == old_c)
                        delta--;
                    if (grid[i][j - 1] == new_c)
                        delta++;
                }

                if (j < W - 1)
                {
                    if (grid[i][j + 1] == old_c)
                        delta--;
                    if (grid[i][j + 1] == new_c)
                        delta++;
                }

                ans = max(ans, total + delta);
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