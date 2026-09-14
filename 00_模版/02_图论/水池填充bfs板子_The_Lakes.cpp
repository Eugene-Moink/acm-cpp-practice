/* =====================================================
BFS 连通块模板（二维网格）

【用途】
  在二维网格（如地图、矩阵）中，从某个起点出发，搜索所有连通且满足条件的格子。
  常用于“求连通块大小”、“求连通块内数值之和”、“求最大连通块”等经典题目。

【参数】
  startX, startY (int): 起点坐标（0-based 下标）。
  n, m (int): 网格行数和列数。
  grid (vector<vector<int>>&): 存储网格数值，0 表示障碍或已访问，非 0 表示可通过。
  visited (vector<vector<bool>>&): 标记数组，避免重复访问（也可直接用 grid 置 0，但用 visited 更通用且不破坏原数据）。

【返回值】
  ll: 该连通块内所有格子的数值之和（或格子的数量，取决于 grid 存储的内容）。

【核心结构】
  queue<pair<int, int>>: 存放待扩展的坐标。
  dx[4], dy[4]: 四方向移动（上下左右）。若需八方向（含对角线），需扩为 8 个方向数组。

===================================================== */
ll bfs(int startX, int startY, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    if (startX < 0 || startX >= n || startY < 0 || startY >= m)
        return 0;
    if (visited[startX][startY] || grid[startX][startY] == 0)
        return 0;

    // 四方向移动（上下左右）
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;

    ll sum = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;
        sum += grid[x][y];

        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny] || grid[nx][ny] == 0)
                continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
    return sum;
}