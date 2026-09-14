/*
 * 并查集（DSU）
 *
 * 输入：n（节点数，1-based）、m（操作数），接下来 m 行 op x y
 *       op=1 合并 x, y；op=2 查询 x, y 是否连通（Y/N）
 * 复杂度：均摊 O(alpha(n)) ≈ O(1)，空间 O(n)
 *
 * 易错：find 里的路径压缩 fa[x] = find(fa[x]) 不能少
 * 多组数据：取消 main 中 // cin >> T; 的注释，并在 solve 里重新 init
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

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

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
            cout << (dsu.isSame(x, y) ? "Y\n" : "N\n");
        }
    }
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