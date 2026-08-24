#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> grid[i];
    }

    vector<bool> row_f(H, false), col_f(W, false);
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == '#')
            {
                row_f[i] = true;
                col_f[j] = true;
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(H, vector<int>(W, -1));

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == '.' && !row_f[i] && !col_f[j])
            {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            if (grid[nx][ny] == '#')
                continue;
            if (dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    int ans = 0;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == '.' && dist[i][j] != -1 && dist[i][j] <= K)
            {
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

    moink();
    return 0;
}