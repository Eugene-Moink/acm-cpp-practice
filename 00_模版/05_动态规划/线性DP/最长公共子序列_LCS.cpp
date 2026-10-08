/*
 * 最长公共子序列 LCS
 *
 * 【用途】求两个序列（字符串）的最长公共子序列长度，以及滚动数组压缩、最长公共子串的区分、LCS 字符串还原。
 * 【输入】a、b（两个字符串，可以为空串，下标 0-based 传入）
 * 【输出】最长公共子序列的长度（int）/ 还原出的 LCS 字符串（string）
 * 【复杂度】lcs_length 与 lcs_length_rolling 时间 O(n * m)，空间分别为 O(n * m) 与 O(m)；
 *           lcs_string 时间 O(n * m)，空间 O(n * m)
 * 【易错提醒】DP 表用 1-based 下标最省事（dp[i][j] 对应 a 的前 i 个字符和 b 的前 j 个字符），
 *             循环里读字符要写成 a[i - 1] == b[j - 1]；
 *             滚动数组只保留一行，此时不能再用 dp[i - 1][j - 1]，必须先用变量 pre 存下旧值；
 *             最长公共子串要求连续，状态转移中不等时必须置 0 并把答案取 max，不能沿用 dp[i - 1][j - 1]。
 *
 * 多组数据：dp 表在函数内新建，无需手动清空。
 */

int lcs_length(const string &a, const string &b)
{
    int n = (int)a.size();
    int m = (int)b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

/* ==================== 滚动数组压成一维（只求长度） ==================== */

int lcs_length_rolling(const string &a, const string &b)
{
    int n = (int)a.size();
    int m = (int)b.size();

    vector<int> dp(m + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int pre = 0;
        for (int j = 1; j <= m; j++)
        {
            int old = dp[j];
            if (a[i - 1] == b[j - 1])
            {
                dp[j] = pre + 1;
            }
            else
            {
                dp[j] = max(dp[j], dp[j - 1]);
            }
            pre = old;
        }
    }

    return dp[m];
}

/* ==================== 最长公共子串（连续，状态不等时必须置 0） ==================== */

int lcs_substring_length(const string &a, const string &b)
{
    int n = (int)a.size();
    int m = (int)b.size();

    vector<int> dp(m + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[j] = dp[j - 1] + 1;
            }
            else
            {
                dp[j] = 0;
            }
            if (dp[j] > ans)
            {
                ans = dp[j];
            }
        }
    }

    return ans;
}

/* ==================== 还原 LCS 字符串（从 dp[n][m] 回溯） ==================== */

string lcs_string(const string &a, const string &b)
{
    int n = (int)a.size();
    int m = (int)b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string res;
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            res.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    string a, b;
    cin >> a >> b;

    cout << lcs_length(a, b) << "\n";           // 二维 DP
    cout << lcs_length_rolling(a, b) << "\n";   // 一维滚动
    cout << lcs_string(a, b) << "\n";           // 还原出的一个 LCS
    cout << lcs_substring_length(a, b) << "\n"; // 最长公共子串长度（连续）
    ==================================================================== */
