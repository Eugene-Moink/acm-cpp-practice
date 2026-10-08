/* =====================================================
BFS 连通块（二维网格 Flood Fill）

【用途】
  从起点出发向四方向扩散，求该连通块内格子的数值之和（也可改成计数或求最大块）。
【输入】
  startX, startY 起点坐标（0-based）；n, m 网格行列数；
  grid 保存网格数值，0 表示障碍；visited 为访问标记数组。
【输出】
  ll，该连通块内所有格子的数值之和（grid 全存 1 时即为块大小）。
【复杂度】
  O(n·m)。
【易错提醒】
  1. 起点越界、已被访问或为障碍时返回 0，调用方不需要先判。
  2. 入队时就置 visited，不要等出队再置，否则同一格子会重复入队。
  3. 需要八方向时把 dx / dy 扩成 8 个方向数组。
  4. 递归 flood fill 在 n·m 很大时会爆栈，此时必须用 BFS。
===================================================== */
ll flood_fill(int startX, int startY, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    if (startX < 0 || startX >= n || startY < 0 || startY >= m)
        return 0;
    if (visited[startX][startY] || grid[startX][startY] == 0)
        return 0;

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
