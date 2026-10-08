/*
 * 网格路径 DP（只能向右 / 向下移动）
 *
 * 【用途】在 n 行 m 列的网格上，求从左上角 (0,0) 走到右下角 (n-1,m-1) 的路径方案数（'.' 可走、'#' 障碍），
 *         以及每个格子有权值时的最小路径和。
 * 【输入】n、m（网格行列数）；方案数版本传入 vector<string> g（长度 n，每行 m 个字符，'.' 可走 '#' 为障碍）；
 *         最小路径和版本传入 vector<vector<ll>> a（n 行 m 列的格子权值，可为负）
 * 【输出】左上到右下的路径方案数（对 MOD 取模）/ 左上到右下的最小路径和
 * 【复杂度】时间 O(n * m)，空间 O(n * m)（可滚动数组压到 O(m)）
 * 【易错提醒】dp[0][0] 必须单独初始化（起点的方案数 / 权值），不要塞进双层循环里重复累加；
 *             障碍点直接置 0 并 continue，不能参与转移；
 *             边界 i == 0 || j == 0 只有一个方向能过来，写成 dp[i-1][j] + dp[i][j-1] 会把越界或 0 重复计入；
 *             最小路径和版本到达不了的位置要置成 INF，不能留 0；
 *             上面的前提是「只能向右 / 向下」，如果可以四方向移动，障碍网格求方案数要用 BFS/DFS 计数（有环会退化），
 *             最小路径和若权值非负用 Dijkstra、权值可负用 Bellman-Ford，DP 不适用。
 *
 * 多组数据：dp 数组在函数内新建，无需手动清空。
 */

const int MOD = 998244353;

ll grid_paths(int n, int m, const vector<string> &g)
{
    if (n <= 0 || m <= 0)
        return 0;
    if (g[0][0] == '#' || g[n - 1][m - 1] == '#')
        return 0;

    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '#')
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (i == 0)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    return dp[n - 1][m - 1];
}

/* ==================== 最小路径和 ==================== */

const ll INF = 1e18;

ll grid_min_sum(int n, int m, const vector<vector<ll>> &a)
{
    if (n <= 0 || m <= 0)
        return 0;

    vector<vector<ll>> dp(n, vector<ll>(m, INF));
    dp[0][0] = a[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] + a[i][j];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + a[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
            }
        }
    }

    return dp[n - 1][m - 1];
}

/* 滚动数组写法（方案数版本，空间 O(m)）：
 *   vector<ll> dp(m, 0);
 *   dp[0] = (g[0][0] == '.') ? 1 : 0;
 *   逐行滚动时 dp[j] 代表当前行，dp[j]（更新前）代表上一行，单独处理 j == 0 即可。
 */

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];
    cout << grid_paths(n, m, g) << "\n";

    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cout << grid_min_sum(n, m, a) << "\n";
    ==================================================================== */
