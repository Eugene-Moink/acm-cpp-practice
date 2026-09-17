/*
 * 最小生成树 Kruskal
 *
 * 输入：n（点数，1-based）、m（边数），接下来 m 行 u v w（无向边）
 * 输出：最小生成树总边权；若图不连通输出 -1
 * 复杂度：O(m log m)，适合稀疏图
 *
 * 依赖：并查集
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

struct DSU
{
    vector<int> fa;

    DSU(int n = 0) { init(n); }

    void init(int n)
    {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }

    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy)
            fa[fx] = fy;
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }
};

struct Edge
{
    int u, v;
    ll w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

ll kruskal(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end());
    DSU dsu(n);

    ll ans = 0;
    int cnt = 0;

    for (const auto &e : edges)
    {
        if (!dsu.isSame(e.u, e.v))
        {
            dsu.merge(e.u, e.v);
            ans += e.w;
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }

    if (cnt == n - 1)
        return ans;
    return -1;
}

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    ll ans = kruskal(n, edges);
    if (ans == -1)
        cout << "orz\n";
    else
        cout << ans << "\n";
}
