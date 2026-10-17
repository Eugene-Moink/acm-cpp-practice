/* =====================================================
背包_二维费用

【用途】
  每个物品同时消耗两种资源（例如「花费」与「精力」、或「体积」与「重量」），
  求在两种资源上限内、按「件数最多优先、同样多件时消耗最小」的双目标 0/1 背包。
  典型题：洛谷 P1509 找啊找啊找GF。
【输入】
  n 个物品的 Pack2DItem{ c1, c2, t }：分别消耗资源一、资源二，以及第二目标的代价 t；
  资源上限 cap1、cap2。
【输出】
  pair<int, ll>{ 最多件数, 在件数最多前提下的最小总 t }。
【复杂度】
  O(n · cap1 · cap2) 时间、O(cap1 · cap2) 空间。
【易错提醒】
  1. 两个维度都必须倒序枚举；只要有一个写成正序，就变成「该物品可无限取」。
  2. 双目标比较必须写全：先比件数多，件数相同再比 t 小；只比一个会错。
  3. dp 用 pair{0, 0} 作初值表示「一件都不取」，天然可转移；
     若题目要求「必须恰好装满两种资源」，才把初值改成 -INF 且只允许从可达状态转移。
  4. 答案是整张表的最优值（资源可以不装满），不是单一的 dp[cap1][cap2]。
  5. 要还原具体选了哪些物品，需要额外记录决策表（每个状态最后一步选了谁）。
===================================================== */
struct Pack2DItem
{
    int c1, c2;
    ll t;
};

pair<int, ll> knapsack_2d(int cap1, int cap2, const vector<Pack2DItem> &items)
{
    vector<vector<pair<int, ll>>> dp(cap1 + 1, vector<pair<int, ll>>(cap2 + 1, {0, 0}));

    for (const Pack2DItem &it : items)
    {
        for (int i = cap1; i >= it.c1; i--)
        {
            for (int j = cap2; j >= it.c2; j--)
            {
                pair<int, ll> prev = dp[i - it.c1][j - it.c2];
                pair<int, ll> cand = {prev.first + 1, prev.second + it.t};
                if (cand.first > dp[i][j].first ||
                    (cand.first == dp[i][j].first && cand.second < dp[i][j].second))
                {
                    dp[i][j] = cand;
                }
            }
        }
    }

    pair<int, ll> best = {0, 0};
    for (int i = 0; i <= cap1; i++)
    {
        for (int j = 0; j <= cap2; j++)
        {
            if (dp[i][j].first > best.first ||
                (dp[i][j].first == best.first && dp[i][j].second < best.second))
            {
                best = dp[i][j];
            }
        }
    }
    return best;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<Pack2DItem> items(n);
    for (int i = 0; i < n; i++)
        cin >> items[i].c1 >> items[i].c2 >> items[i].t;

    int cap1, cap2;
    cin >> cap1 >> cap2;

    pair<int, ll> ans = knapsack_2d(cap1, cap2, items);
    cout << ans.first << " " << ans.second << "\n";   // 最多几件、最小总耗时
   ==================================================================== */
