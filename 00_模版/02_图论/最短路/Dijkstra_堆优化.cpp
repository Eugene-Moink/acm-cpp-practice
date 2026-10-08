/* =====================================================
堆优化 Dijkstra（单源最短路，非负权）

【用途】
  非负权图的单源最短路。
【输入】
  n（点数，1-based）、m（边数），接下来 m 行 u v w（有向边），最后读入起点 s。
【输出】
  起点到每个点的最短距离，不可达输出 INF。
【复杂度】
  O((N+M) log N)。
【易错提醒】
  1. 边权必须非负；有负权请用 02_图论/最短路/SPFA与Bellman-Ford.cpp。
  2. dist 必须用 ll，INF 取 1e18，别用 int。
  3. 用 vis[u]（或 `d != dist[u]`）跳过过期堆项，否则可能 TLE。
  4. 无向图请加上注释掉的那行反向边。
  5. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */
const ll INF = 1e18;

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    vector<vector<pair<int, ll>>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // 无向图请加上下面这行
        // g[v].push_back({u, w});
    }

    int s;
    cin >> s;

    vector<ll> dist(n + 1, INF);
    vector<bool> vis(n + 1, false);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = true;

        for (auto [v, w] : g[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        if (i < n)
            cout << " ";
    }
    cout << "\n";
}