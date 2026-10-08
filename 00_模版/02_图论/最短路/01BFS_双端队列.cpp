/*
 * 01BFS（双端队列 BFS，边权只有 0 和 1 的最短路）
 *
 * 【用途】边权为 0 / 1 的图上求单源最短路：邻接表通用版 + 二维网格版（可破墙）。
 * 【输入】通用版：n（点数，1-based）、起点 s、邻接表 g（g[u] = {v, w}，w 只能是 0 或 1）；
 *         网格版：H、W、字符网格 grid（grid[i][j]）、起点 (sx, sy)、障碍字符 obstacle。
 * 【输出】通用版：vector<ll> 各点最短路（不可达保持 INF）；
 *         网格版：vector<vector<ll>> 每个格子到起点的最小代价（不可达保持 INF）。
 * 【复杂度】时间 O(N + M)（每个点可能多次入队，但总松弛次数是 O(M)），空间 O(N + M)。
 * 【易错提醒】1. 只能用 0 / 1 边权；出现 w >= 2 或负权时结果错误，请改用 Dijkstra；
 *             2. 必须用 dist[u] + w < dist[v] 松弛，不要用 visited 提前剪枝——
 *                同一个点可能先以较大代价入队、之后被 0 权边改小，提前标记会漏掉更优解；
 *             3. 松弛成功时 w == 0 走 push_front、w == 1 走 push_back，写反会退化成普通 BFS；
 *             4. 通用版用 deque<int> 存点，网格版用 deque<pair<int, int>> 存坐标；
 *             5. 网格版把「进入障碍格」的代价记为 1（破墙），若障碍格根本不能进入，那是普通 BFS 而不是 01BFS。
 */
const ll INF = 1e18;

/* ==================== 一、邻接表通用版 ==================== */

vector<ll> bfs01(int s, int n, const vector<vector<pair<int, int>>> &g)
{
    vector<ll> dist(n + 1, INF);
    deque<int> dq;

    dist[s] = 0;
    dq.push_front(s);

    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();

        for (auto [v, w] : g[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;

                if (w == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }

    return dist;
}

/* ==================== 二、二维网格版（障碍格代价 1） ==================== */

int dx4[4] = {1, -1, 0, 0};
int dy4[4] = {0, 0, 1, -1};

vector<vector<ll>> bfs01_grid(int H, int W, const vector<string> &grid, int sx, int sy, char obstacle)
{
    vector<vector<ll>> dist(H, vector<ll>(W, INF));
    deque<pair<int, int>> dq;

    dist[sx][sy] = 0;
    dq.push_front(make_pair(sx, sy));

    while (!dq.empty())
    {
        pair<int, int> cur = dq.front();
        dq.pop_front();

        int x = cur.first;
        int y = cur.second;

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx4[k];
            int ny = y + dy4[k];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            int w = (grid[nx][ny] == obstacle) ? 1 : 0;

            if (dist[x][y] + w < dist[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + w;

                if (w == 0)
                    dq.push_front(make_pair(nx, ny));
                else
                    dq.push_back(make_pair(nx, ny));
            }
        }
    }

    return dist;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<pair<int, int>>> g(n + 1);          // 权值只能是 0 / 1
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // 无向图请加上下面这行
        // g[v].push_back({u, w});
    }

    vector<ll> dist = bfs01(s, n, g);
    for (int i = 1; i <= n; i++)
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    cout << "\n";

    int H, W, sx, sy;
    char obstacle;
    cin >> H >> W >> sx >> sy >> obstacle;
    vector<string> grid(H);
    for (int i = 0; i < H; i++)
        cin >> grid[i];

    vector<vector<ll>> d = bfs01_grid(H, W, grid, sx, sy, obstacle);
    cout << (d[H - 1][W - 1] == INF ? -1 : d[H - 1][W - 1]) << "\n";
==================================================================== */
