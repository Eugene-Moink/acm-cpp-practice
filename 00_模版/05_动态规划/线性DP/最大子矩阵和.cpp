/*
 * 最大子矩阵和
 *
 * 【用途】在一个 n 行 m 列的整数矩阵中选一个子矩阵（行、列都连续），使元素之和最大。
 * 【输入】n、m 和矩阵 a（vector<vector<ll>>，n 行 m 列，元素可正可负）
 * 【输出】最大子矩阵和（ll）；矩阵全为负数时返回其中最大的单个元素
 * 【复杂度】枚举上下边界 O(n^2) 乘每行 Kadane O(m)：时间 O(n^2 * m)，空间 O(m)（列前缀和版本额外 O(n * m)）
 * 【易错提醒】1. Kadane 的 best 必须用 LLONG_MIN 初始化：全负数矩阵的答案是最大单元素，用 0 初始化会错答 0；
 *             2. 枚举上边界后，下边界要逐行把 a[bottom][j] 累加进 col[j]，不要每换一次下边界就重算整段列和（会多一个 O(n)）；
 *             3. 下界从 top 开始枚举即可覆盖所有行区间，写成全部 n^2 对会做一倍无用功；
 *             4. 列前缀和版本取列和是 pre[bottom + 1][j] - pre[top][j]，注意 +1 偏移别写反；
 *             5. 行数远多于列数时先把矩阵转置再算，让枚举跑短的维度：O(min(n, m)^2 * max(n, m))。
 *
 * 多组数据：col、pre 都在函数内新建，无全局状态，反复调用即可。
 */

/* ==================== 一、枚举上下边界 + 逐行累加列和 + 内联 Kadane（O(n^2 * m)，空间 O(m)） ==================== */

ll max_submatrix_sum(int n, int m, const vector<vector<ll>> &a)
{
    if (n <= 0 || m <= 0)
    {
        return 0;
    }

    ll best = LLONG_MIN;

    for (int top = 0; top < n; top++)
    {
        vector<ll> col(m, 0);

        for (int bottom = top; bottom < n; bottom++)
        {
            for (int j = 0; j < m; j++)
            {
                col[j] += a[bottom][j];
            }

            ll cur = 0;
            for (int j = 0; j < m; j++)
            {
                cur += col[j];
                if (cur > best)
                {
                    best = cur;
                }
                if (cur < 0)
                {
                    cur = 0;
                }
            }
        }
    }

    return best;
}

/* ==================== 二、列前缀和优化：列和 O(1) 取出，省掉逐次累加的中间数组 ==================== */

ll max_submatrix_sum_prefix(int n, int m, const vector<vector<ll>> &a)
{
    if (n <= 0 || m <= 0)
    {
        return 0;
    }

    vector<vector<ll>> pre(n + 1, vector<ll>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pre[i + 1][j] = pre[i][j] + a[i][j];
        }
    }

    ll best = LLONG_MIN;

    for (int top = 0; top < n; top++)
    {
        for (int bottom = top; bottom < n; bottom++)
        {
            ll cur = 0;
            for (int j = 0; j < m; j++)
            {
                ll col_sum = pre[bottom + 1][j] - pre[top][j];
                cur += col_sum;
                if (cur > best)
                {
                    best = cur;
                }
                if (cur < 0)
                {
                    cur = 0;
                }
            }
        }
    }

    return best;
}

/* ==================== 三、与一维最大子段和的关系 ====================
 *   固定上下边界后，把每一列在 [top, bottom] 内的和求出来，就得到一个长度为 m 的一维数组；
 *   最大子矩阵和就是这个一维数组的最大子段和，也就是 00_基础工具\最大子段和_Kadane算法.cpp 里的 max_subarray_sum。
 *   所以整体框架可以看成「O(n^2) 枚举行区间 + 对每个行区间跑一次 Kadane」：
 *   本文件为了自包含，把那段 Kadane 直接内联进循环，best 的初值与一维版本保持一致，同样用 LLONG_MIN。
 * ==================== */

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    cout << max_submatrix_sum(n, m, a) << "\n";           // 逐行累加列和版
    cout << max_submatrix_sum_prefix(n, m, a) << "\n";    // 列前缀和版，两者答案相同

    // 例：a = {{1, 2, -1}, {-3, 4, 5}} -> 10（两行都取，列取第 2、3 列：2 + (-1) + 4 + 5）
    // 只要一维的最大子段和（不限制行区间）直接用 00_基础工具\最大子段和_Kadane算法.cpp
    ==================================================================== */
