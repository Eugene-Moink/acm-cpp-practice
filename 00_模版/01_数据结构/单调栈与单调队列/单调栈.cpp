/*
 * 【用途】单调栈模板（三个独立片段）：右侧第一个更大元素、右侧第一个更小元素、直方图最大矩形面积。
 * 【输入】next_greater / next_smaller 传入 vector<int> 数组 a（0-based，允许为空）；
 *         largest_rectangle 传入直方图高度数组 heights（vector<int>，允许为空）。
 * 【输出】next_greater / next_smaller 返回 vector<int>，第 i 位是 a[i] 右侧第一个更大 / 更小元素的下标，不存在为 -1；
 *         largest_rectangle 返回最大矩形面积（ll）。
 * 【复杂度】三个函数均为 O(n) 时间、O(n) 空间（每个下标最多进栈一次、出栈一次）。
 * 【易错提醒】1) 栈里存下标而不是元素值，否则拿不到距离和区间边界；
 *             2) 求「下一个更小」只需把弹栈比较符号反过来（见分节二）；
 *             3) 直方图两侧各加一个高度 0 的哨兵，省去栈的清空与边界特判；
 *             4) 面积用 ll 存放，避免 n * max_h 溢出 int，故相乘前要转成 ll；
 *             5) 元素值可能超过 2^31 时，把数组元素类型整体换成 ll（返回值与中间量同步换）。
 */

/* ==================== 一、下一个更大元素（右侧第一个更大值） ====================
 * 正序扫描，栈内保存「还没找到更大值」的下标，对应高度单调不增；
 * 遇到 a[i] 时，所有高度严格小于 a[i] 的栈顶下标的答案就是 i。
 * ============================================================================ */
vector<int> next_greater(const vector<int> &a)
{
    int n = (int)a.size();
    vector<int> nxt(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nxt;
}

/* ==================== 二、下一个更小元素（写法差异说明） ====================
 * 与分节一完全同构，唯一差异是把弹栈条件 a[st.top()] < a[i] 反过来写成 a[st.top()] > a[i]；
 * 反过来之后栈内高度单调不减，某下标被弹出的那一刻，a[i] 就是它右侧第一个更小值。
 * ======================================================================== */
vector<int> next_smaller(const vector<int> &a)
{
    int n = (int)a.size();
    vector<int> nxt(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nxt;
}

/* ==================== 三、直方图最大矩形（栈存下标 + 左右哨兵） ====================
 * h[0] 与 h[n + 1] 是高度 0 的哨兵，保证每根真实柱子两侧都能找到更矮的边界；
 * left[i] / right[i] 是 i 两侧第一个严格更矮的位置，柱子 i 能扩展的宽度是 right[i] - left[i] - 1。
 * ================================================================================ */
ll largest_rectangle(const vector<int> &heights)
{
    vector<int> h;
    h.reserve(heights.size() + 2);
    h.push_back(0);
    h.insert(h.end(), heights.begin(), heights.end());
    h.push_back(0);

    int n = (int)h.size();
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && h[st.top()] > h[i])
        {
            right[st.top()] = i;
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll width = (ll)right[i] - left[i] - 1;
        ans = max(ans, (ll)h[i] * width);
    }
    return ans;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> g = next_greater(a);
    for (int i = 0; i < n; i++)
        cout << a[i] << " 右侧第一个更大值的下标 = " << g[i] << "\n";

    vector<int> s = next_smaller(a);
    for (int i = 0; i < n; i++)
        cout << a[i] << " 右侧第一个更小值的下标 = " << s[i] << "\n";

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    cout << largest_rectangle(heights) << "\n";
   ==================================================================== */
