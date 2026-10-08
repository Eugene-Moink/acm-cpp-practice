/* =====================================================
最小生成树 Kruskal

【用途】
  求无向图的最小生成树总边权，适合稀疏图。
【输入】
  n（点数，1-based）、m（边数），接下来 m 行 u v w（无向边）。
【输出】
  最小生成树总边权；图不连通时 kruskal 返回 -1（示例输出 orz）。
【复杂度】
  O(M log M)。
【易错提醒】
  1. 本文件内联了一份 DSU，与 01_数据结构/并查集/并查集_路径压缩.cpp 重复，一次只贴一个。
  2. 边表要按边权升序排序；判环靠并查集，无向边只需存一条。
  3. 选够 n − 1 条边即为最小生成树，不足说明图不连通。
  4. 边权与累加结果都必须用 ll。
  5. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */

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
