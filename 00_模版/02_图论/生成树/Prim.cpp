/*
 * 最小生成树 Prim（朴素版，适合稠密图）
 *
 * 输入：n（点数，1-based）、m（边数），接下来 m 行 u v w（无向边）
 * 输出：最小生成树总边权；若图不连通输出 -1
 * 复杂度：O(n^2)，适合稠密图（m 接近 n^2）
 *
 * 说明：从节点 1 开始扩展，每次选取距离生成树最近的点加入
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

const ll INF = 1e18;

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    vector<vector<ll>> g(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        g[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        // 有重边取最小值
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }

    vector<ll> dist(n + 1, INF);
    vector<bool> vis(n + 1, false);

    dist[1] = 0;
    ll ans = 0;
    int cnt = 0;

    for (int iter = 0; iter < n; iter++)
    {
        int u = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (u == -1 || dist[u] == INF)
        {
            cout << "orz\n";
            return;
        }

        vis[u] = true;
        ans += dist[u];
        cnt++;

        for (int v = 1; v <= n; v++)
        {
            if (!vis[v] && g[u][v] < dist[v])
            {
                dist[v] = g[u][v];
            }
        }
    }

    cout << ans << "\n";
}
