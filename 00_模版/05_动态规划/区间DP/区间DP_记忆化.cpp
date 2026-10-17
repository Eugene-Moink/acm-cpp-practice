/* =====================================================
区间DP_记忆化

【用途】
  区间 DP 的通用框架：dfs(l, r) 表示「只考虑区间 [l, r]」的最优值，
  由枚举拆分点 k 把 [l, r] 拆成 [l, k] 与 [k+1, r] 转移。
  同时给出「成环 / 断环成链」写法（数组复制成 2n，答案取所有起点）。
【输入】
  区间长度 n、区间值 a[1..n]（1-based）
  cost(l, r, k)：把 [l, k] 与 [k+1, r] 合并的代价（按题意自己写）
【输出】
  interval_dfs / interval_dp_bottomup 返回区间 [1, n] 的最优值；
  interval_dp_ring 返回成环情况下的最优值（枚举起点）。
【复杂度】
  状态 O(n²)，单次转移 O(n) → 时间 O(n³)，空间 O(n²)。
  n ≤ 500 可做，n = 1000 时约 1e9 次转移，需要四边形不等式 / Knuth 优化。
【易错提醒】
  1. 空区间 l > r 必须返回 0；单点 l == r 返回 0 还是 a[l] 取决于题意（合并代价模型一般是 0）。
  2. 记忆化用 -1 表示未访问：最优值可能为负时必须换 -INF 或另开 visited 数组。
  3. 拆分点枚举 k ∈ [l, r-1]，写成 k < r；漏掉 k = r 会少一半转移。
  4. 成环不要「do 一次再循环」，直接复制成 2n 数组后对每个起点 dfs(start, start+n-1) 取最优。
  5. dp 开 n + 2 张表；从 0 开始编号时下标整体平移。
  6. 记忆化递归深度 O(n)，n 很大时改自底向上（按 len 枚举）。
===================================================== */
vector<ll> interval_dp_val;
vector<vector<ll>> interval_dp_memo;

ll interval_dfs(int l, int r, const function<ll(int, int, int)> &cost)
{
    if (l > r)
    {
        return 0;
    }
    if (l == r)
    {
        return 0;
    }

    ll &res = interval_dp_memo[l][r];
    if (res != -1)
    {
        return res;
    }

    res = LLONG_MIN / 4;
    for (int k = l; k < r; k++)
    {
        res = max(res, interval_dfs(l, k, cost) + interval_dfs(k + 1, r, cost) + cost(l, r, k));
    }
    return res;
}

ll interval_dp(int n, const vector<ll> &a, const function<ll(int, int, int)> &cost)
{
    interval_dp_val = a;
    interval_dp_memo.assign(n + 2, vector<ll>(n + 2, -1));
    return interval_dfs(1, n, cost);
}

/* 自底向上版：按区间长度从小到大推，避免递归开销 */
ll interval_dp_bottomup(int n, const vector<ll> &a, const function<ll(int, int, int)> &cost)
{
    vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            dp[l][r] = LLONG_MIN / 4;
            for (int k = l; k < r; k++)
            {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + cost(l, r, k));
            }
        }
    }
    return dp[1][n];
}

/* 成环 / 断环成链：把环复制成 2n 的链，枚举起点，取长度为 n 的区间的最优值 */
ll interval_dp_ring(int n, const vector<ll> &a, const function<ll(int, int, int)> &cost)
{
    vector<ll> b(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i];
        b[i + n] = a[i];
    }

    ll best = LLONG_MIN / 4;
    for (int start = 1; start <= n; start++)
    {
        interval_dp_val = b;
        interval_dp_memo.assign(2 * n + 2, vector<ll>(2 * n + 2, -1));
        best = max(best, interval_dfs(start, start + n - 1, cost));
    }
    return best;
}

/* 消除型（配对消除、区间染色等）把转移换成题目自己的配对规则，例如：
 *   if (pos[l] <= r) res = max(res, (pos[l]-l+1)^2 ... + interval_dfs(pos[l]+1, r));
 *   else            res = max(res, 1 + interval_dfs(l+1, r));
 * 再叠加拆分转移 for (k = l; k < r; k++) res = max(res, dfs(l,k) + dfs(k+1,r));
 * 见 old/Maximize_the_Score.cpp —— 该类题的「配对的另一端点」要预处理 pos[]。
 */

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 例：石子合并，合并 [l, k] 与 [k+1, r] 的代价是两段之和
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    auto cost = [&](int l, int r, int k)
    {
        return pre[r] - pre[l - 1];
    };

    cout << interval_dp_bottomup(n, a, cost) << "\n";   // 链
    cout << interval_dp_ring(n, a, cost) << "\n";        // 环（取 max）
   ==================================================================== */
