/* =====================================================
序列比对_三状态DP（仿射空位罚分）

【用途】
  两条序列做「比对」：每一步可以选择
    0 = 配对：s1[i] 与 s2[j] 对齐，得分 matchCost(s1[i], s2[j])；
    1 = 在 s1 中插入空位（消耗 s2 的一个字符），罚分；
    2 = 在 s2 中插入空位（消耗 s1 的一个字符），罚分。
  空位罚分分离「开启」与「延续」：第一次插入罚 A，紧接着继续插入罚 B（仿射空位 / affine gap）。
  典型题：洛谷 P4059 序列比对。
【输入】
  s1、s2：两个字符串（长度 n、m，1-based 处理时注意下标）；
  matchCost(a, b)：配对得分；openPenalty：开启空位罚分；extendPenalty：延续空位罚分。
【输出】
  最大总得分（ll）。
【复杂度】
  O(n·m) 时间、O(n·m) 空间（滚动数组可压到 O(m)）。
【易错提醒】
  1. 三个状态的含义不要搞混：状态 1「在 s1 里插空位」消耗 s2 的字符，状态 2 反之。
  2. 空位「开启」只能从状态 0（配对）转来；「延续」只能从同一个空位状态转来。
  3. 边界要单独初始化：dp[i][0][2] = 只能连续插入；dp[0][j][1] 同理；dp[0][0][0] = 0。
  4. 不可达状态用 -INF，转移前必须判 != -INF，否则 -INF + 正分会污染答案。
  5. 最终答案是 max(dp[n][m][0..2])，只看状态 0 会漏掉「最后一步是空位」的情况。
  6. s1 / s2 从 0 开始编号时，状态转移里的 i-1 / j-1 不要写成 i / j。
===================================================== */
ll align_affine(const string &s1, const string &s2,
                const function<ll(char, char)> &matchCost,
                ll openPenalty, ll extendPenalty)
{
    int n = (int)s1.size(), m = (int)s2.size();
    const ll NEG = LLONG_MIN / 4;

    // dp[i][j][0] 配对结尾 / [1] 在 s1 中插入空位 / [2] 在 s2 中插入空位
    vector<vector<vector<ll>>> dp(n + 1,
                                  vector<vector<ll>>(m + 1, vector<ll>(3, NEG)));
    dp[0][0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0][2] = dp[i - 1][0][0] - openPenalty;
        if (i > 1)
        {
            dp[i][0][2] = max(dp[i][0][2], dp[i - 1][0][2] - extendPenalty);
        }
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j][1] = dp[0][j - 1][0] - openPenalty;
        if (j > 1)
        {
            dp[0][j][1] = max(dp[0][j][1], dp[0][j - 1][1] - extendPenalty);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 配对
            ll best = max({dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]});
            if (best != NEG)
            {
                dp[i][j][0] = max(dp[i][j][0], best + matchCost(s1[i - 1], s2[j - 1]));
            }

            // 在 s1 中插入空位（消耗 s2[j-1]，即 j 前进、i 不动）
            if (dp[i][j - 1][0] != NEG)
            {
                dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - openPenalty);
            }
            if (dp[i][j - 1][1] != NEG)
            {
                dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1] - extendPenalty);
            }

            // 在 s2 中插入空位（消耗 s1[i-1]）
            if (dp[i - 1][j][0] != NEG)
            {
                dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][0] - openPenalty);
            }
            if (dp[i - 1][j][2] != NEG)
            {
                dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j][2] - extendPenalty);
            }
        }
    }

    return max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
}

/* ==================== 调用示例（贴进自己的 main） ====================
    string s1, s2;
    cin >> s1 >> s2;

    // 例：配对的得分来自一张 4×4 的表 score[c1][c2]
    auto cost = [&](char a, char b)
    {
        return (ll)score[id(a)][id(b)];
    };

    ll A, B;
    cin >> A >> B;             // 空位开启 / 延续罚分
    cout << align_affine(s1, s2, cost, A, B) << "\n";
   ==================================================================== */
