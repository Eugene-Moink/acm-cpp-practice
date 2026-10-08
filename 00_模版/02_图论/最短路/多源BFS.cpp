/* =====================================================
多源 BFS（二维网格）

【用途】
  多个起点同时向外扩散，求每个格子到最近起点的最短步数（边权均为 1）。
【输入】
  H, W，grid（vector<string>），start_char 起点字符，obstacle 障碍字符。
【输出】
  vector<vector<int>>，不可达的格子为 INF。
【复杂度】
  O(H·W)。
【易错提醒】
  1. 所有起点必须在 BFS 开始前一次性全部入队，否则会退化成单源 BFS。
  2. 入队时就标记 dist，不要等出队再判断，否则同一格子会重复入队。
  3. dx8 / dy8 是八方向；只走上下左右请用 dx4 / dy4。
  4. obstacle 默认传 '\0' 表示没有障碍。
  5. 本文件的 INF 是 int 版（1e9），与最短路模板的 ll 版 INF 不是同一个。
===================================================== */
const int INF = 1e9;

int dx4[4] = {1, -1, 0, 0};
int dy4[4] = {0, 0, 1, -1};

int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<vector<int>> multi_source_bfs(int H, int W, const vector<string> &grid, char start_char, char obstacle = '\0')
{
    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<pair<int, int>> q;

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == start_char)
            {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int k = 0; k < 4; ++k)
        {
            int nx = x + dx4[k];
            int ny = y + dy4[k];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            if (obstacle != '\0' && grid[nx][ny] == obstacle)
                continue;

            if (dist[nx][ny] != INF)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return dist;
}

void solve()
{
    int H, W;
    if (!(cin >> H >> W))
        return;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
        cin >> grid[i];

    char start_char, obstacle;
    cin >> start_char >> obstacle;

    vector<vector<int>> dist = multi_source_bfs(H, W, grid, start_char, obstacle);

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (dist[i][j] == INF)
                cout << "-1";
            else
                cout << dist[i][j];
            if (j + 1 < W)
                cout << " ";
        }
        cout << "\n";
    }
}