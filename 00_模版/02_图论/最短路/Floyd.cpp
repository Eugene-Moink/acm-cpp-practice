/*
 * Floyd 全源最短路
 *
 * 输入：n（点数，1-based）、m（边数），接下来 m 行 u v w
 * 输出：所有点对之间的最短距离
 * 复杂度：O(N^3)，适用于 N ≤ 500
 *
 * 注意：
 *   1. 初始化 dist[i][i] = 0，其余为 INF
 *   2. 有重边取最小值
 *   3. 允许负权边，但不允许负环
 *   4. 三重循环顺序：k 必须在最外层！
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */
const ll INF = 1e18;

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        // 有重边取最小值
        dist[u][v] = min(dist[u][v], w);
        // 无向图请加上下面这行
        // dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] == INF || dist[k][j] == INF)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF";
            else
                cout << dist[i][j];
            if (j < n)
                cout << " ";
        }
        cout << "\n";
    }
}