#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 多源 BFS 模板（C++11 兼容，无结构化绑定）
// 适用场景：多个起点同时向外扩散，求每个点到最近起点的最短距离
// 典型应用：多个火源蔓延、多安全点扩散、多入口最短路

vector<vector<int>> multi_source_bfs(
    int H,
    int W,
    const vector<string> &grid,
    const vector<vector<bool>> &is_source,
    char obstacle = '#')
{
    // 1. 距离数组，-1 表示未访问
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> q;

    // 2. 方向数组（上下左右）
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // 3. 所有起点入队，距离设为 0
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (is_source[i][j])
            {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    // 4. BFS 扩散
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

            // 越界检查
            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            // 障碍物检查（默认为 '#'，可自定义）
            if (grid[nx][ny] == obstacle)
                continue;

            // 已访问检查
            if (dist[nx][ny] != -1)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return dist;
}