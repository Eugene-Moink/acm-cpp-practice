/*
 * =====================================================
 * 并查集（DSU）+ 最小生成树（Kruskal算法）模板
 * =====================================================
 *
 * 【用途】
 * 1. 并查集：维护连通性，支持合并集合与查询是否同属一个集合。
 * 2. Kruskal：给定 n 个节点和 m 条带权无向边，求最小生成树的总边权。
 *    常用于图论中的“修路、建桥、铺电线”等最小代价连通问题。
 *
 * 【结构体说明】
 * struct DSU
 *   - init(n): 初始化 n 个节点，各自独立。
 *   - find(x): 查找根节点（带路径压缩）。
 *   - merge(x, y): 合并两个节点所在的集合。
 *   - isSame(x, y): 判断两个节点是否属于同一集合。
 *   均摊时间复杂度 O(alpha(n)) ≈ O(1)。
 *
 * struct Edge
 *   - 包含 u, v, w 三个成员，分别表示起点、终点、边权。
 *   - 重载了 < 运算符，按边权从小到大排序。
 *
 * 【核心函数说明】
 * ll kruskal(int n, vector<Edge> &edges)
 *   - 参数 n: 节点总数（编号 1 到 n）。
 *   - 参数 edges: 存储所有边的数组。
 *   - 返回值: 最小生成树的总边权。若图不连通返回 -1。
 *   - 时间复杂度: O(m log m)（排序为主），空间复杂度 O(n)。
 *
 * 【算法原理】
 * 按边权从小到大排序，依次尝试加入每条边。若该边连接的两个节点尚未连通
 * （不在同一个集合），则加入该边，并合并集合。当加入的边数达到 n-1 时，
 * 树构建完成。利用“贪心”思想，局部最优解即全局最优解。
 *
 * 【如何适配多组测试数据】
 * 默认只跑 1 组数据。如果题目输入文件含多组独立的测试用例
 * （例如第一行给定总组数 T），把 main() 函数中 // cin >> T;
 * 前面的注释去掉即可。
 * =====================================================
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    ll result = kruskal(n, edges);
    if (result == -1)
        cout << "orz\n";
    else
        cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}