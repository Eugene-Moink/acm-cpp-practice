/* =====================================================
LCA（倍增法）最近公共祖先

【用途】
  求树上两点的最近公共祖先，并顺带支持树上两点距离。
【输入】
  n（点数，1-based，根固定为 1）、q（查询数）；接下来 n−1 行 u v（无向边），再 q 行 u v。
【输出】
  每个查询的 LCA；dist(u, v) 返回两点间的边数距离。
【复杂度】
  预处理 O(N log N)，单次查询 O(log N)。
【易错提醒】
  1. LOG 要满足 2^LOG > n；n ≤ 2e5 时取 20 足够，n 更大必须同步调大。
  2. up[root][*] = 0，靠全局数组零初始化兜底，多组数据要保证重算。
  3. 多组数据时 g[] 要 clear；depth / up 会被 bfs 覆盖，但前提是树连通。
  4. 图不连通（森林）时必须对每个根各跑一次 bfs。
  5. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */

const int MAXN = 200005;
const int LOG = 20;

int n, q;
vector<int> g[MAXN];
int depth[MAXN];
int up[MAXN][LOG];

void bfs(int root)
{
    queue<int> que;
    vector<bool> vis(n + 1, false);

    vis[root] = true;
    depth[root] = 0;
    up[root][0] = 0;
    for (int j = 1; j < LOG; j++)
    {
        up[root][j] = 0;
    }
    que.push(root);

    while (!que.empty())
    {
        int u = que.front();
        que.pop();

        for (int v : g[u])
        {
            if (vis[v])
                continue;
            vis[v] = true;
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            for (int j = 1; j < LOG; j++)
            {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }
            que.push(v);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    int diff = depth[u] - depth[v];
    for (int j = 0; j < LOG; j++)
    {
        if (diff >> j & 1)
            u = up[u][j];
    }

    if (u == v)
        return u;

    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }

    return up[u][0];
}

int dist(int u, int v)
{
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void solve()
{
    if (!(cin >> n >> q))
        return;

    for (int i = 1; i <= n; i++)
        g[i].clear();

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}