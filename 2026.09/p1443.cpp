#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dist[405][405];

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dist[i][j] = -1;
        }
    }

    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        for (int k = 0; k < 8; k++)
        {
            int nx = cur.first + dx[k];
            int ny = cur.second + dy[k];

            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}