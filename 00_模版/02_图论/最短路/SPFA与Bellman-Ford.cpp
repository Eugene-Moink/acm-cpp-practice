/*
 * SPFA 与 Bellman-Ford（单源最短路 / 负环判定）
 *
 * 【用途】带负权边的单源最短路：SPFA 队列优化松弛、SPFA 判负环、
 *         Bellman-Ford 松弛 n-1 轮及负环判定（可作对照写法）。
 * 【输入】n（点数，1-based）、起点 s、邻接表 g（g[u] = {v, w}，有向边）；
 *         Bellman-Ford 另外需要边表 edges（BFEdge{u, v, w}）。
 * 【输出】spfa：各点最短距离 vector<ll>（不可达保持 INF）；
 *         spfa_negative_cycle / bellman_ford：bool，true 表示存在从 s 可达的负环。
 * 【复杂度】SPFA 平均 O(k·M)（k 为每点平均入队次数），最坏 O(N·M)；Bellman-Ford 固定 O(N·M)。
 * 【易错提醒】1. 非负权图请用堆优化 Dijkstra，不要用 SPFA（网格 / 菊花图能把它卡到最坏）；
 *             2. SPFA 最坏 O(N·M)，能写 Dijkstra 就别赌；
 *             3. 起点不可达的点距离保持 INF，输出时按 INF 特判，别拿 INF 参与真实距离的加减；
 *             4. cnt[v] = cnt[u] + 1 统计的是「当前最短路经过的边数」，cnt[v] >= n 说明有负环；
 *             5. 两种判负环只对「从 s 可达」的负环有效，要判整图负环得加超级源点
 *                （0 号点向 1..n 各连一条 0 权边，再从 0 号点跑）；
 *             6. 无向图每条边要正反各加一次，出现负权无向边就等价于负环。
 */
const ll INF = 1e18;

struct BFEdge
{
    int u, v;
    ll w;
};

/* ==================== 一、SPFA 求单源最短路 ==================== */

vector<ll> spfa(int s, int n, const vector<vector<pair<int, ll>>> &g)
{
    vector<ll> dist(n + 1, INF);
    vector<bool> inq(n + 1, false);
    queue<int> q;

    dist[s] = 0;
    q.push(s);
    inq[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;

        for (auto [v, w] : g[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;

                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }

    return dist;
}

/* ==================== 二、SPFA 判负环 ==================== */

bool spfa_negative_cycle(int s, int n, const vector<vector<pair<int, ll>>> &g)
{
    vector<ll> dist(n + 1, INF);
    vector<int> cnt(n + 1, 0);
    vector<bool> inq(n + 1, false);
    queue<int> q;

    dist[s] = 0;
    q.push(s);
    inq[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inq[u] = false;

        for (auto [v, w] : g[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;

                if (cnt[v] >= n)
                    return true;

                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }

    return false;
}

/* ==================== 三、Bellman-Ford 松弛 n-1 轮 ==================== */

bool bellman_ford(int s, int n, const vector<BFEdge> &edges, vector<ll> &dist)
{
    dist.assign(n + 1, INF);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        bool changed = false;

        for (const BFEdge &e : edges)
        {
            if (dist[e.u] == INF)
                continue;

            if (dist[e.u] + e.w < dist[e.v])
            {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }

        if (!changed)
            break;
    }

    for (const BFEdge &e : edges)
    {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v])
            return true;
    }

    return false;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<pair<int, ll>>> g(n + 1);
    vector<BFEdge> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        edges.push_back({u, v, w});
        // 无向图请加上下面这两行
        // g[v].push_back({u, w});
        // edges.push_back({v, u, w});
    }

    vector<ll> dist = spfa(s, n, g);                  // 若含可达负环，dist 无意义

    if (spfa_negative_cycle(s, n, g))
        cout << "spfa: 存在可达负环" << "\n";

    if (bellman_ford(s, n, edges, dist))
        cout << "bellman-ford: 存在可达负环" << "\n";

    for (int i = 1; i <= n; i++)
        cout << (dist[i] == INF ? -1 : dist[i]) << " ";
    cout << "\n";
==================================================================== */
