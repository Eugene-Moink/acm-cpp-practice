/*
 * 数位 DP（记忆化搜索模板）
 *
 * 【用途】统计 [1, n]（或 [l, r]）中满足「按十进制拆位后满足某条件」的数的个数。
 *         本文件的具体例子：十进制表示中不含连续相同数字的数，即相邻两位不相等。
 * 【输入】n（上界，long long 范围）、l、r（区间版本）
 * 【输出】满足条件的数的个数（long long），[1, n] 区间 / [l, r] 区间
 * 【复杂度】时间 O(位数 * 状态数 * 10)，空间 O(位数 * 状态数 * 4)
 * 【易错提醒】limit 表示当前位是否贴着上界（为真时不能取满 0..9，只能取到 digit[pos]）；
 *             lead 表示是否还在前导零（为真时这一位可以继续不放数字，且相邻位比较要跳过）；
 *             memo 只有在 !limit && !lead 时才可复用，贴着上界或仍在前导零时状态与具体上界有关，写进 memo 会污染后续询问；
 *             n 要用 long long，n <= 0 时必须特判返回 0（不能直接拿负数去拆位）；
 *             多询问时 memo 可以只清一次吗？不能，若条件与外部参数（如目标数位和）有关，每组参数都要重置。
 *
 * 多组数据：本模板每次 count_upto 前都会清空 memo，直接调用即可。
 */

const int DIGIT_MAXLEN = 20;

int digit_buf[DIGIT_MAXLEN];
ll memo_digit[DIGIT_MAXLEN][10][2][2];
bool vis_digit[DIGIT_MAXLEN][10][2][2];

/* 相邻两位不相等：prev_digit 是上一位数字，lead 为真时表示前面还没有数字 */
ll dfs_digit(int pos, int prev_digit, bool limit, bool lead)
{
    if (pos < 0)
    {
        return lead ? 0 : 1;
    }
    if (!limit && !lead && vis_digit[pos][prev_digit][0][0])
    {
        return memo_digit[pos][prev_digit][0][0];
    }

    int up = limit ? digit_buf[pos] : 9;
    ll res = 0;

    for (int d = 0; d <= up; d++)
    {
        bool nxt_limit = limit && (d == up);
        bool nxt_lead = lead && (d == 0);

        if (!nxt_lead && !lead && d == prev_digit)
        {
            continue;
        }
        res += dfs_digit(pos - 1, d, nxt_limit, nxt_lead);
    }

    if (!limit && !lead)
    {
        vis_digit[pos][prev_digit][0][0] = true;
        memo_digit[pos][prev_digit][0][0] = res;
    }

    return res;
}

/* 统计 [1, n] 内不含连续相同数字的数的个数；n <= 0 返回 0 */
ll count_upto(ll n)
{
    if (n <= 0)
    {
        return 0;
    }

    int len = 0;
    while (n > 0)
    {
        digit_buf[len++] = (int)(n % 10);
        n /= 10;
    }

    memset(vis_digit, 0, sizeof(vis_digit));
    memset(memo_digit, 0, sizeof(memo_digit));

    return dfs_digit(len - 1, 0, true, true);
}

/* 统计 [l, r] 内满足条件的数的个数 */
ll count_range(ll l, ll r)
{
    if (l > r)
    {
        return 0;
    }
    return count_upto(r) - count_upto(l - 1);
}

/* 换成别的条件只需改两处：
 *   ① 状态（上面用 prev_digit；若条件与数位和有关，就把 state 换成「当前数位和」，但 memo 的维度要跟着改成对应上界 + 1，
 *      并且这种与外部参数相关的状态不能在多组询问之间复用 memo）；
 *   ② dfs 里 continue / 计数的那几行。
 * 一般的 state 写法：memo[pos][state][2][2] 四维，前两维是状态，后两维分别是 limit 和 lead，
 * 用 vis 标记或直接把 memo 初始化为 -1 均可；本模板只缓存 !limit && !lead 的格子，等价且更省内存。
 */

/* ==================== 调用示例（贴进自己的 main） ====================
    ll n;
    cin >> n;
    cout << count_upto(n) << "\n";      // [1, n] 内不含连续相同数字的个数

    ll l, r;
    cin >> l >> r;
    cout << count_range(l, r) << "\n";  // [l, r] 内不含连续相同数字的个数
    ==================================================================== */
