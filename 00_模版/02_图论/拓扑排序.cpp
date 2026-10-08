/*
 * 拓扑排序（Kahn 入度法）+ 判环 + DAG 最长路
 *
 * 【用途】有向图拓扑排序、判断有向图是否有环、在 DAG 上按拓扑序做最长路 DP。
 * 【输入】n（点数，1-based）、邻接表 g（g[u] = u 的所有出边终点）、入度数组 indeg（下标 1..n 有效）；
 *         最长路还需要拓扑序 topo 和起点 s。
 * 【输出】topo_sort：拓扑序 vector<int>（长度 < n 说明有环）；
 *         topo_has_cycle：bool；dag_longest_path：从 s 出发到各点的最长路边数（不可达为 NEG_INF）。
 * 【复杂度】时间 O(N + M)，空间 O(N)。
 * 【易错提醒】1. 模板里 indeg 是「传值」的：topo_sort 内部会把它减到 0，原始入度数组不会被破坏；
 *                如果你想复用原入度数组，就自己先拷一份再传进去（传值副本已经替你兜住了）；
 *             2. 重边会重复计入度（u->v 两条边让 indeg[v] 加 2），Kahn 里同样会被减两次，一般无害，
 *                但统计入度时不要漏加或多加；
 *             3. 自环会让该点入度永远减不到 0，此时拓扑序长度必然 < n；
 *             4. 拓扑序不唯一，Kahn 用 queue 得到的是任意一个；要字典序最小就把 queue 换成
 *                priority_queue<int, vector<int>, greater<int>>；
 *             5. 有环时拓扑序不完整，最长路 DP 只对拓扑序里出现过的点有意义，先判环再算 DP；
 *             6. 最长路 DP 的下标初值是 NEG_INF，判断不可达要用 dp[u] == NEG_INF，不能写 dp[u] < 0。
 */
const ll NEG_INF = -1e18;

/* ==================== 一、Kahn 入度法求拓扑序 ==================== */

vector<int> topo_sort(int n, const vector<vector<int>> &g, vector<int> indeg)
{
    vector<int> order;
    order.reserve(n);

    queue<int> q;

    for (int u = 1; u <= n; u++)
    {
        if (indeg[u] == 0)
            q.push(u);
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : g[u])
        {
            indeg[v]--;

            if (indeg[v] == 0)
                q.push(v);
        }
    }

    return order;
}

/* ==================== 二、判环（拓扑序长度 < n 即有环） ==================== */

bool topo_has_cycle(int n, const vector<vector<int>> &g, const vector<int> &indeg)
{
    return (int)topo_sort(n, g, indeg).size() < n;
}

/* ==================== 三、DAG 最长路（按拓扑序转移，边数版） ==================== */

vector<ll> dag_longest_path(int n, const vector<vector<int>> &g, const vector<int> &topo, int s)
{
    vector<ll> dp(n + 1, NEG_INF);
    dp[s] = 0;

    for (int u : topo)
    {
        if (dp[u] == NEG_INF)
            continue;

        for (int v : g[u])
        {
            if (dp[u] + 1 > dp[v])
                dp[v] = dp[u] + 1;
        }
    }

    return dp;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        indeg[v]++;
    }

    vector<int> topo = topo_sort(n, g, indeg);        // 传值，原 indeg 不会被改
    for (int u : topo)
        cout << u << " ";
    cout << "\n";

    if (topo_has_cycle(n, g, indeg))
        cout << "有环" << "\n";

    vector<ll> dp = dag_longest_path(n, g, topo, s);
    for (int i = 1; i <= n; i++)
        cout << (dp[i] == NEG_INF ? -1 : dp[i]) << " ";
    cout << "\n";

    // 边带权时把 dp[u] + 1 换成 dp[u] + 边权即可（负权也能处理，DAG 无后效性）
==================================================================== */
