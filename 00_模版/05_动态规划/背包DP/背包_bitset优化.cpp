/* =====================================================
背包_bitset优化

【用途】
  把「子集和能否凑出」的可行性背包从 O(n·V) 压到 O(n·V/64)：
  bitset 的 | 与 << 一条指令并行处理 64 位，常数直接除以 64。
  典型用法：DSU 缩点后把每个连通块大小当物品做可行性背包（洛谷 P2170）、
            多重背包的二进制拆分后做 0/1 背包、求最接近某个值的可达和。
【输入】
  weights：每个物品的重量（0/1 背包语义，每件只用一次）；V：答案关心的最大容量。
【输出】
  subset_sum 返回 bitset，第 j 位为 1 表示能凑出和 j；
  closest_subset_sum 返回 ≤ target 的最大可达和（凑不出返回 0）。
【复杂度】
  O(n · V / 64) 时间、O(V / 8) 字节空间。
【易错提醒】
  1. bitset 的位数必须是编译期常量，用 const int 定义上界，别用变量。
  2. 0/1 物品写法是 dp |= (dp << w)；完全背包（无限个）不能这么写，
     要么按「for (j = w; j <= V; j++) dp[j] |= dp[j-w]」的逐位思路，要么二进制拆分。
  3. 数量上限 cnt 的物品用二进制拆分成 1, 2, 4, …, 余数，共 O(log cnt) 个 0/1 物品。
  4. 别忘 dp[0] = 1；求最接近 target 时从 target 向下扫到 0。
  5. V 很大（>1e7）时 bitset 也要 1MB 以上，注意多组数据不要重复构造。
===================================================== */
const int BITSET_MAXV = 200005;

bitset<BITSET_MAXV> subset_sum(const vector<int> &weights)
{
    bitset<BITSET_MAXV> dp;
    dp.reset();
    dp[0] = 1;
    for (int w : weights)
    {
        if (w >= 0 && w < BITSET_MAXV)
        {
            dp |= (dp << w);
        }
    }
    return dp;
}

/* 求 ≤ target 的最大可达子集和 */
int closest_subset_sum(const bitset<BITSET_MAXV> &dp, int target)
{
    for (int s = min(target, BITSET_MAXV - 1); s >= 0; s--)
    {
        if (dp[s])
        {
            return s;
        }
    }
    return 0;
}

/* 有限数量物品展开成 0/1 物品：w 个重量为 weight 的物品，拆成 1,2,4,… 组 */
void binary_split(int weight, int cnt, vector<int> &out)
{
    for (int k = 1; cnt > 0; k <<= 1)
    {
        int take = min(k, cnt);
        out.push_back(weight * take);
        cnt -= take;
    }
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, m;
    cin >> n >> m;

    // 例：DSU 合并后，把每个连通块的大小当物品
    vector<int> blockSize = get_block_sizes(n);      // 每个连通块的人数
    bitset<BITSET_MAXV> dp = subset_sum(blockSize);

    int low = -1, high = -1;
    for (int i = m; i >= 0; i--)
        if (dp[i]) { low = i; break; }
    for (int i = m; i <= n; i++)
        if (dp[i]) { high = i; break; }
    cout << (low < 0 ? high : (high < 0 ? low : (m - low <= high - m ? low : high))) << "\n";

    // 多重背包转 0/1：
    // vector<int> ws;
    // binary_split(weight, cnt, ws);
    // auto reach = subset_sum(ws);
   ==================================================================== */
