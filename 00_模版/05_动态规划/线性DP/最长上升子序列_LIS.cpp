/*
 * 最长上升子序列 LIS
 *
 * 【用途】求序列中最长严格递增子序列的长度（元素不必连续），以及非递减版本的写法与子序列下标还原。
 * 【输入】a（长度为 n 的整数序列，n 可以为 0）
 * 【输出】最长上升子序列的长度（int）
 * 【复杂度】lis_n2 时间 O(n^2) 空间 O(n)；lis_nlogn 时间 O(n log n) 空间 O(n)；还原下标时间 O(n^2) 空间 O(n)
 * 【易错提醒】O(n log n) 写法里 dp 数组存的是「长度为 i+1 的上升子序列的最小结尾」，它本身不是某个具体子序列；
 *             严格递增用 lower_bound（替换第一个 >= a[i]），非递减用 upper_bound（替换第一个 > a[i]）；
 *             序列为空或 n == 0 时返回 0，不要访问 dp[0]。
 *
 * 多组数据：dp 数组在函数内新建，无需手动清空。
 */

int lis_n2(const vector<int> &a)
{
    int n = (int)a.size();
    if (n == 0)
        return 0;

    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }

    return ans;
}

/* ==================== O(n log n) 贪心 + 二分（严格递增，lower_bound） ==================== */

int lis_nlogn(const vector<int> &a)
{
    vector<int> dp;

    for (int x : a)
    {
        int pos = (int)(lower_bound(dp.begin(), dp.end(), x) - dp.begin());
        if (pos == (int)dp.size())
        {
            dp.push_back(x);
        }
        else
        {
            dp[pos] = x;
        }
    }

    return (int)dp.size();
}

/* ==================== 非严格递增 / 非递减（upper_bound，只差一个函数名） ==================== */

int lis_nlogn_nondecreasing(const vector<int> &a)
{
    vector<int> dp;

    for (int x : a)
    {
        int pos = (int)(upper_bound(dp.begin(), dp.end(), x) - dp.begin());
        if (pos == (int)dp.size())
        {
            dp.push_back(x);
        }
        else
        {
            dp[pos] = x;
        }
    }

    return (int)dp.size();
}

/* ==================== 还原具体子序列下标（O(n^2) DP + parent 回溯） ==================== */

vector<int> lis_scheme(const vector<int> &a)
{
    int n = (int)a.size();
    if (n == 0)
        return {};

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);
    int best = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > dp[best])
        {
            best = i;
        }
    }

    vector<int> order;
    for (int i = best; i != -1; i = parent[i])
    {
        order.push_back(i);
    }

    reverse(order.begin(), order.end());
    return order;
}

/* 若只需要「每个位置结尾的 LIS 长度」而不需要最小的结尾值，用 O(n^2) 的 dp[i]；
 * O(n log n) 版本要还原下标，需额外维护 pos[i]（a[i] 被放到的位置）与 pre[i]（该位置上一个下标），
 * 两者在替换发生时同步更新，最后从最大有效位置顺着 pre 回溯。
 */

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << lis_n2(a) << "\n";                    // O(n^2) 版本
    cout << lis_nlogn(a) << "\n";                 // O(n log n) 严格递增
    cout << lis_nlogn_nondecreasing(a) << "\n";   // 非递减

    vector<int> idx = lis_scheme(a);              // 一组最长上升子序列的下标
    for (int i = 0; i < (int)idx.size(); i++)
        cout << idx[i] << " \n"[i + 1 == (int)idx.size()];
    ==================================================================== */
