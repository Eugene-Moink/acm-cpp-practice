/* =====================================================
多重背包_计数

【用途】
  每种物品有上限 cnt[i] 件（不是 1 件、也不是无限件），求凑出容量 j 的「方案数」（不是最大价值）。
  典型题：洛谷 P1077 摆花。
  另附：用滑动窗口把 O(n·m·cnt) 优化到 O(n·m) 的写法。
【输入】
  n 种物品、容量上限 m、每种物品数量上限 cnt[1..n]、模数 mod。
【输出】
  vector<ll> dp，dp[j] = 凑出容量 j 的方案数（已对 mod 取模）。
【复杂度】
  multipack_count：O(n · m · maxcnt)；
  multipack_count_fast：O(n · m)（滑动窗口求「上一行连续 cnt+1 项之和」）。
【易错提醒】
  1. 计数型多重背包不能套「一维正序完全背包」的写法：完全背包是多项式展开（无限件），
     限额版本必须按「上一行」转移，所以要么二维表，要么每层新建 ndp 再交换。
  2. k 的上界是 min(j, cnt[i])，写成 j 会越界 / 多算。
  3. dp[0] = 1（什么都不取算一种方案）；「恰好装满」的答案就是 dp[m]。
  4. 滑动窗口版要记得窗口越界时减掉 dp[j - cnt - 1]，并用 ((x % mod) + mod) % mod 归正。
  5. 方案数往往很大，别忘取模；若题目要「至少 / 至多」则再对答案求和或前缀和。
===================================================== */
vector<ll> multipack_count(int n, int m, const vector<int> &cnt, ll mod)
{
    vector<ll> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        vector<ll> ndp(m + 1, 0);
        for (int j = 0; j <= m; j++)
        {
            int lim = min(j, cnt[i]);
            for (int k = 0; k <= lim; k++)
            {
                ndp[j] = (ndp[j] + dp[j - k]) % mod;
            }
        }
        dp.swap(ndp);
    }
    return dp;
}

/* 等价但更快：ndp[j] = Σ_{t = max(0, j - cnt[i])}^{j} dp[t]，
 * 用长度为 cnt[i] + 1 的滑动窗口维护区间和，转移 O(1)。*/
vector<ll> multipack_count_fast(int n, int m, const vector<int> &cnt, ll mod)
{
    vector<ll> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        vector<ll> ndp(m + 1, 0);
        ll window = 0;
        for (int j = 0; j <= m; j++)
        {
            window += dp[j];
            if (j - cnt[i] - 1 >= 0)
            {
                window -= dp[j - cnt[i] - 1];
            }
            window %= mod;
            if (window < 0)
            {
                window += mod;
            }
            ndp[j] = window;
        }
        dp.swap(ndp);
    }
    return dp;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, m;
    cin >> n >> m;                 // n 种花，m 盆
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> cnt[i];

    const ll MOD = 1000007;
    vector<ll> dp = multipack_count(n, m, cnt, MOD);
    cout << dp[m] << "\n";
   ==================================================================== */
