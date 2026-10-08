/*
 * 二分图染色判定（BFS 二染色）
 *
 * 【用途】判断无向图是否为二分图；以及返回一份具体染色方案的版本（可用于划分两侧点集）。
 * 【输入】n（点数，1-based）、邻接表 g（g[u] = 与 u 相邻的所有点，无向边必须双向加）。
 * 【输出】is_bipartite：bool；
 *         bipartite_color：vector<int>，下标 1..n，值为 0 / 1 两种颜色，未染色为 -1；
 *         不是二分图时返回空 vector。
 * 【复杂度】时间 O(N + M)，空间 O(N)。
 * 【易错提醒】1. 自环、任意奇环都会让染色失败（自环时 v == u，颜色与自己冲突，直接返回 false）；
 *             2. 无向边必须双向加（g[u] 加 v、g[v] 加 u），只加单向会把奇环漏判成二分图；
 *             3. 图可能不连通，必须对每个仍未染色的点都当作新起点重新 BFS 一次；
 *             4. 孤立点也算二分图，它的颜色是 0（每个连通分量内部可以整体翻转 0/1，方案不唯一）；
 *             5. 判重靠 color[v] 是否为 -1，不要另开 visited：颜色数组本身就记录了访问状态。
 */

/* ==================== 一、只判是否二分图 ==================== */

bool is_bipartite(int n, const vector<vector<int>> &g)
{
    vector<int> color(n + 1, -1);
    queue<int> q;

    for (int s = 1; s <= n; s++)
    {
        if (color[s] != -1)
            continue;

        color[s] = 0;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : g[u])
            {
                if (color[v] == -1)
                {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
                else if (color[v] == color[u])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

/* ==================== 二、返回染色方案 ==================== */

vector<int> bipartite_color(int n, const vector<vector<int>> &g)
{
    vector<int> color(n + 1, -1);
    queue<int> q;

    for (int s = 1; s <= n; s++)
    {
        if (color[s] != -1)
            continue;

        color[s] = 0;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : g[u])
            {
                if (color[v] == -1)
                {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
                else if (color[v] == color[u])
                {
                    return vector<int>();
                }
            }
        }
    }

    return color;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);                            // 无向边必须双向加
    }

    if (is_bipartite(n, g))
        cout << "是二分图" << "\n";

    vector<int> color = bipartite_color(n, g);
    if (color.empty())
        cout << "不是二分图" << "\n";
    else
        for (int i = 1; i <= n; i++)
            cout << i << " -> " << color[i] << "\n";
==================================================================== */
