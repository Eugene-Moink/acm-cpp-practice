/*
 * 子序列匹配（贪心双指针）
 *
 * 【用途】
 *   判断字符串 s 是否为字符串 t 的子序列；以及由此派生的
 *   「最少删除多少字符」「匹配结束位置」「逐字符 find」等写法。
 *
 * 【输入】
 *   t：被匹配的长串（文本串）；s：要匹配的短串（模式串）。
 *   注意参数顺序：is_subsequence(t, s) 表示在 t 中按顺序找 s 的字符。
 *
 * 【输出】
 *   is_subsequence(t, s)：bool，s 是 t 的子序列返回 true，否则 false。
 *   subsequence_min_deletions(t, s)：int，把 s 变成 t 的子序列最少要删掉 s 的字符数。
 *   subsequence_match_end(t, s)：int，s 在 t 中贪心匹配完成的下标（0 起）；不是子序列返回 -1。
 *   subsequence_is_sub_via_find(t, s)：bool，与 is_subsequence 等价的 find 写法。
 *
 * 【复杂度】
 *   is_subsequence：O(|t|)；subsequence_min_deletions：O(|t| + |s|)；
 *   subsequence_match_end：O(|t|)；subsequence_is_sub_via_find：O(|t| * 字符比较开销)。
 *
 * 【易错提醒】
 *   1. 子序列 ≠ 子串：子序列可以不连续，子串必须连续；本题是子序列，用指针顺序扫即可，
 *      不要套 KMP（KMP 解决的是子串匹配）。
 *   2. 空串约定：s 为空时任意 t 都满足子序列（返回 true），此时最少删除 0 个字符、
 *      结束位置返回 -1；t 为空而 s 非空时一定返回 false。
 *   3. 指针只能前进不能回头：内层 while 找到 t[j] == s[i] 后必须 j++，不能重新从头扫描。
 *   4. s 比 t 长时不可能匹配，可以先 if (s.size() > t.size()) return false 剪枝。
 *   5. 多组询问同一个 t 时，逐个 O(|t|) 扫描会超时，应改用 nxt[i][c] 预处理跳转表。
 */

const ll INF = 1e18;
const int MOD = 998244353;

/* ==================== ① 核心：O(n) 判断子序列 ==================== */

bool is_subsequence(const string &t, const string &s)
{
    int i = 0;
    int n = (int)s.size();
    int m = (int)t.size();

    for (int j = 0; j < m && i < n; j++)
    {
        if (t[j] == s[i])
            i++;
    }

    return i == n;
}

/* ==================== ② 最少删除多少字符 / 匹配结束位置 ==================== */

int subsequence_min_deletions(const string &t, const string &s)
{
    int n = (int)s.size();
    int m = (int)t.size();
    int i = 0;

    for (int j = 0; j < m && i < n; j++)
    {
        if (t[j] == s[i])
            i++;
    }

    return n - i;
}

int subsequence_match_end(const string &t, const string &s)
{
    int n = (int)s.size();
    int m = (int)t.size();
    int i = 0;

    if (n == 0)
        return -1;

    for (int j = 0; j < m && i < n; j++)
    {
        if (t[j] == s[i])
            i++;
    }

    if (i != n)
        return -1;

    return i - 1;
}

/* ==================== ③ string::find 的等价写法 ==================== */

bool subsequence_is_sub_via_find(const string &t, const string &s)
{
    size_t pos = 0;

    for (size_t i = 0; i < s.size(); i++)
    {
        pos = t.find(s[i], pos);
        if (pos == string::npos)
            return false;
        pos++;
    }

    return true;
}

/* ==================== ④ 与 KMP（子串匹配）的区别 ====================
   子序列匹配：字符可以不相邻，只需保持相对顺序，贪心双指针 O(|t|) 即最优。
   子串匹配：字符必须连续，暴力 O(|t| * |s|)，用 KMP / Z 函数优化到 O(|t| + |s|)。
   判断「s 是否为 t 的子序列」不要去写 KMP，那是解决另一类问题的。
==================================================================== */

/* ==================== 调用示例（贴进自己的 main） ====================
    string t, s;
    cin >> t >> s;

    cout << (is_subsequence(t, s) ? "yes" : "no") << "\n";

    cout << subsequence_min_deletions(t, s) << "\n";   // 最少删除 s 的字符数

    cout << subsequence_match_end(t, s) << "\n";       // 匹配结束下标，不是子序列为 -1

    cout << (subsequence_is_sub_via_find(t, s) ? "yes" : "no") << "\n";
==================================================================== */
