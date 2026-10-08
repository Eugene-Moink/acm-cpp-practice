/*
 * 完全背包（每件物品可以选无限次）
 *
 * 【用途】在容量 V 的背包中挑选若干物品（每件可用任意多次），求最大总价值；
 *         以及「恰好装满」「求方案数」「装满时的最大件数」三种常见变形。
 * 【输入】V（背包容量，非负整数）、w（下标 0..n-1 的重量，均为正整数）、v（对应价值，与 w 等长）
 * 【输出】最大总价值 / 恰好装满的最大总价值 / 方案数 / 装满时的最大件数（具体见分节）
 * 【复杂度】时间 O(n * V)，空间 O(V)
 * 【易错提醒】一维滚动数组必须「容量正序」枚举，这样同一件物品才能被反复选取；
 *             写成一维时正序是完全背包、倒序是 01 背包，两者别写混；
 *             求方案数版本每一步都要取模，否则会溢出（方案数版本与物品价值无关）；
 *             求最大件数时 dp 初值用 -1 表示不可达，不能用 0。
 *
 * 多组数据：每轮开始前必须把 dp 数组重新初始化（滚动数组不会自动清空）。
 */

ll knapsack_full(int V, const vector<int> &w, const vector<ll> &v)
{
    vector<ll> dp(V + 1, 0);

    for (int i = 0; i < (int)w.size(); i++)
    {
        for (int j = w[i]; j <= V; j++)
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

const ll NEG_INF = -1e18;

ll knapsack_full_exact(int V, const vector<int> &w, const vector<ll> &v)
{
    vector<ll> dp(V + 1, NEG_INF);
    dp[0] = 0;

    for (int i = 0; i < (int)w.size(); i++)
    {
        for (int j = w[i]; j <= V; j++)
        {
            if (dp[j - w[i]] > NEG_INF / 2 && dp[j - w[i]] + v[i] > dp[j])
            {
                dp[j] = dp[j - w[i]] + v[i];
            }
        }
    }

    return dp[V];
}

/* ==================== 求方案数（每种面额可用无限次，凑出 n 元的方案数） ==================== */

const int MOD = 998244353;

ll coin_count(int n, const vector<int> &coin)
{
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < (int)coin.size(); i++)
    {
        for (int j = coin[i]; j <= n; j++)
        {
            dp[j] = (dp[j] + dp[j - coin[i]]) % MOD;
        }
    }

    return dp[n];
}

/* ==================== 装满时的最大件数（dp 初值 -1 表示不可达） ==================== */

int max_items_full(int V, const vector<int> &w)
{
    vector<int> dp(V + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < (int)w.size(); i++)
    {
        for (int j = w[i]; j <= V; j++)
        {
            if (dp[j - w[i]] != -1 && dp[j - w[i]] + 1 > dp[j])
            {
                dp[j] = dp[j - w[i]] + 1;
            }
        }
    }

    return dp[V];
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int V, n;
    cin >> V >> n;
    vector<int> w(n);
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    cout << knapsack_full(V, w, v) << "\n";          // 最大价值
    cout << knapsack_full_exact(V, w, v) << "\n";    // 恰好装满，装不满输出 -1e18
    cout << max_items_full(V, w) << "\n";            // 装满时的最大件数，装不满输出 -1

    int money;
    cin >> money;
    vector<int> coin(n);                             // 面额
    for (int i = 0; i < n; i++)
        cin >> coin[i];
    cout << coin_count(money, coin) << "\n";         // 凑出 money 的方案数（与顺序无关）
    ==================================================================== */
