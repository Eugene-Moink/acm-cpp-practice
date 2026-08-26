#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* =====================================================
并查集（DSU）底层依赖
【用途】配合 Kruskal 算法使用，判断连通性。
【核心操作】
  init(n):  初始化，每个节点独立。
  find(x):  查找根节点（带路径压缩）。
  merge(x,y): 合并两个集合。
  isSame(x,y): 判断是否在同一集合。
【复杂度】均摊 O(alpha(n)) ≈ O(1)。
===================================================== */
struct DSU
{
    vector<int> fa;
    DSU(int n = 0) { init(n); }
    void init(int n)
    {
        fa.resize(n + 1);
        for (int i = 1; i <= n; ++i)
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

/* =====================================================
最小生成树模板（Kruskal 算法）

【用途】
  给定 n 个节点和 m 条带权边，求能连接所有节点的最小总边权（最小生成树）。
  常用于图论中的“修路、建桥、铺电线”等最小代价连通问题。

【参数】
  n (int): 节点总数（编号 1 到 n）。
  edges (vector<Edge>): 存储边的数组，需要包含 u, v, w。

【返回值】
  ll: 最小生成树的总边权。
  若图不连通（无法生成一棵树），返回 -1。

【全局依赖】
  依赖上方定义的 struct Edge 和 struct DSU。

【算法原理】
  按边权从小到大排序，依次尝试加入每条边。若该边连接的两个节点尚未连通（不在同一个集合），则加入该边，并合并集合。当加入的边数达到 n-1 时，树构建完成。
  利用“贪心”思想，局部最优解即全局最优解。

【复杂度】
  时间复杂度 O(m log m)（排序为主），空间复杂度 O(n)。
===================================================== */
struct Edge
{
    int u, v;
    ll w;
    // 按边权从小到大排序
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
        }
    }
    if (cnt == n - 1)
        return ans; // 成功生成树
    return -1;      // 图不连通
}

/* ==================== 调用示例（原题逻辑） ==================== */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    ll result = kruskal(n, edges);
    if (result == -1)
        cout << "orz\n";
    else
        cout << result << "\n";

    return 0;
}