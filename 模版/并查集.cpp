#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* =====================================================
并查集（DSU）模板

【用途】
  处理不相交集合的合并与查询问题（如判断连通性、动态连通分量计数等）。
  常用于图论题中，判断两个节点是否在同一个连通块内。

【参数】
  n (int): 节点总数（1-based 索引，即节点编号从 1 到 n）。

【成员变量】
  fa (vector<int>): 父节点数组，fa[i] 表示 i 的父节点。路径压缩后，根节点满足 fa[i] == i。

【函数说明】
  init(n):   初始化并查集，每个节点独立成一个集合。
  find(x):   查找 x 所在集合的根节点（附带路径压缩）。
  merge(x,y): 合并 x 和 y 所在的集合（按秩合并可选，这里为简化省略）。
  isSame(x,y): 判断 x 和 y 是否在同一个集合。

【复杂度】
  均摊时间复杂度 O(alpha(n))（Alpha 为反阿克曼函数，近似常数），空间复杂度 O(n)。

【易错提醒】
  1. 下标必须从 1 开始，因此数组开 n+1 大小。
  2. 路径压缩：`return fa[x] = find(fa[x]);` 千万不能少，否则会退化到 O(n)。
  3. 多次测试数据时，务必重新调用 `init(n)`。
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
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
            fa[fx] = fy;
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }
};

/* ==================== 调用示例（原题逻辑） ==================== */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 实例化并查集并初始化
    DSU dsu(n);

    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 1)
        {
            dsu.merge(x, y);
        }
        else if (op == 2)
        {
            if (dsu.isSame(x, y))
            {
                cout << "Y\n";
            }
            else
            {
                cout << "N\n";
            }
        }
    }

    return 0;
}