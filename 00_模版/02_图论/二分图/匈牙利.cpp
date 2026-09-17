/*
 * 二分图最大匹配（匈牙利算法）
 *
 * 输入：n（左部点数）、m（右部点数）、e（边数），接下来 e 行 u v
 * 输出：最大匹配数
 * 复杂度：O(N * E)
 *
 * 说明：
 *   1. 左部节点编号 1~n，右部节点编号 1~m
 *   2. matchR[v] 记录右部节点 v 匹配的左部节点，0 表示未匹配
 *   3. vis[] 每轮清空，防止同一左部节点重复访问同一右部节点
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

void solve()
{
    int n, m, e;
    if (!(cin >> n >> m >> e))
        return;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<int> matchR(m + 1, 0);
    int ans = 0;

    for (int u = 1; u <= n; u++)
    {
        vector<bool> vis(m + 1, false);

        function<bool(int)> dfs = [&](int u) -> bool
        {
            for (int v : g[u])
            {
                if (vis[v])
                    continue;
                vis[v] = true;
                if (matchR[v] == 0 || dfs(matchR[v]))
                {
                    matchR[v] = u;
                    return true;
                }
            }
            return false;
        };

        if (dfs(u))
        {
            ans++;
        }
    }

    cout << ans << "\n";
}
