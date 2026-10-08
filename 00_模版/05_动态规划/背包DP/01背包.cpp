/*
 * 01 背包（每件物品最多选一次）
 *
 * 【用途】在容量 V 的背包中挑选若干物品，每件物品重量 w[i] 价值 v[i]，求最大总价值；
 *         以及「恰好装满」「求方案数」「还原所选物品」三种常见变形。
 * 【输入】V（背包容量，非负整数）、w（下标 0..n-1 的重量，均为非负整数）、v（对应价值，与 w 等长）
 * 【输出】最大总价值 / 恰好装满的最大总价值 / 方案数 / 所选物品的下标序列（具体见分节）
 * 【复杂度】时间 O(n * V)，空间 O(V)
 * 【易错提醒】一维滚动数组必须「容量倒序」枚举，否则同一件物品会被重复选取（退化成完全背包）；
 *             「恰好装满」用 -INF 表示不可达，-INF 相加会溢出，必须先判 dp[j - w[i]] > -INF / 2 再转移；
 *             w[i] == 0 且 v[i] > 0 时倒序保护不了自己，只能选一次需额外特判，正常题意下 w[i] >= 1。
 *
 * 多组数据：每轮开始前必须把 dp 数组重新初始化（滚动数组不会自动清空）。
 */

const ll NEG_INF = -1e18;

ll knapsack01(int V, const vector<int> &w, const vector<ll> &v)
{
    vector<ll> dp(V + 1, 0);

    for (int i = 0; i < (int)w.size(); i++)
    {
        for (int j = V; j >= w[i]; j--)
        {
            if (dp[j - w[i]] + v[i] > dp[j])
            {
                dp[j] = dp[j - w[i]] + v[i];
            }
        }
    }

    return dp[V];
}

/* ==================== 恰好装满（求最大价值，装不满返回 -INF） ==================== */

ll knapsack01_exact(int V, const vector<int> &w, const vector<ll> &v)
{
    vector<ll> dp(V + 1, NEG_INF);
    dp[0] = 0;

    for (int i = 0; i < (int)w.size(); i++)
    {
        for (int j = V; j >= w[i]; j--)
        {
            if (dp[j - w[i]] > NEG_INF / 2 && dp[j - w[i]] + v[i] > dp[j])
            {
                dp[j] = dp[j - w[i]] + v[i];
            }
        }
    }

    return dp[V];
}

/* ==================== 求方案数（下标从 1 开始读入的等价形式 dp[j] += dp[j - w[i]]） ==================== */

const int MOD = 998244353;

ll knapsack01_count(int V, const vector<int> &w)
{
    vector<ll> dp(V + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < (int)w.size(); i++)
    {
        for (int j = V; j >= w[i]; j--)
        {
            dp[j] = (dp[j] + dp[j - w[i]]) % MOD;
        }
    }

    return dp[V];
}

/* ==================== 记录所选物品下标（fill 哨兵 + parent 回溯） ==================== */

vector<int> knapsack01_scheme(int V, const vector<int> &w, const vector<ll> &v)
{
    vector<ll> dp(V + 1, 0);
    vector<int> parent(V + 1, -1);

    for (int i = 0; i < (int)w.size(); i++)
    {
        for (int j = V; j >= w[i]; j--)
        {
            if (dp[j - w[i]] + v[i] > dp[j])
            {
                dp[j] = dp[j - w[i]] + v[i];
                parent[j] = i;
            }
        }
    }

    vector<int> chosen;
    int j = V;
    while (j > 0 && parent[j] != -1)
    {
        int i = parent[j];
        chosen.push_back(i);
        j -= w[i];
    }

    reverse(chosen.begin(), chosen.end());
    return chosen;
}

/* 另一种等价写法：开 vector<vector<char>> take(n + 1, vector<char>(V + 1, 0))，二维 DP 完整保存
 * 每个状态是否选了物品 i，最后从 dp[n][V] 往回走；内存 O(n * V)，n 或 V 较大时用上面的 parent 写法。
 */

/* ==================== 调用示例（贴进自己的 main） ====================
    int V, n;
    cin >> V >> n;
    vector<int> w(n);
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    cout << knapsack01(V, w, v) << "\n";          // 最大价值
    cout << knapsack01_exact(V, w, v) << "\n";    // 恰好装满，装不满输出 -1e18
    cout << knapsack01_count(V, w) << "\n";       // 恰好装满的方案数

    vector<int> pick = knapsack01_scheme(V, w, v);
    for (int i = 0; i < (int)pick.size(); i++)
        cout << pick[i] << " \n"[i + 1 == (int)pick.size()];
    ==================================================================== */
