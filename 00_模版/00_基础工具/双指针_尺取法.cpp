/* =====================================================
双指针 / 尺取法模板（三种场景合订）

【用途】
  1. 同向双指针求「和不超过 S 的最长区间」（要求元素非负）。
  2. 同向双指针求「和至少为 S 的最短区间」（要求元素为正）。
  3. 两个有序数组用双指针配对计数（如 |a - b| <= 1 的最大配对数）。

【输入】
  场景 1 / 2：数组 a（vector<ll>，下标 0-based）、阈值 S (ll)。
  场景 3：两个数组 a、b（先各自排序，或先调用传入的排序版本）。

【输出】
  场景 1：最长区间的长度（无合法区间返回 0）。
  场景 2：最短区间的长度（不存在返回 0）。
  场景 3：最多能配成的对数。

【复杂度】
  场景 1 / 2：O(n)。
  场景 3：O(n log n)（排序） + O(n + m)（双指针）。

【易错提醒】
  1. 场景 1 要求 a[i] >= 0：一旦出现负数，右指针前进不再让和单调不减，滑动窗口失效，此时改用前缀和 + 二分。
  2. 场景 2 要求 a[i] > 0：有 0 或负数时「缩左端点让和变小」不再成立，同样改用前缀和 + 二分。
  3. 左指针 left 只能右移、不能回退，写完之后确认右指针和左指针都是单调的。
  4. sum 的更新必须与指针移动严格配对，漏掉一次 -= 会得到错误答案且很难查。
  5. 场景 3 的贪心已是最优：两数组排序后从小到大能配就配；配对决策由指针位置的元素决定，不要按差值全排序再乱配。
  6. 场景 3 的差要开 long long 再取绝对值，避免 INT_MIN 取负溢出。
===================================================== */

/* ==================== 一、最长区间：和不超过 S ==================== */

int longest_sum_at_most(const vector<ll> &a, ll S)
{
    int n = (int)a.size();
    int left = 0;
    ll sum = 0;
    int best = 0;
    for (int right = 0; right < n; right++)
    {
        sum += a[right];
        while (sum > S)
        {
            sum -= a[left];
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

/* ==================== 二、最短区间：和至少为 S ==================== */

int shortest_sum_at_least(const vector<ll> &a, ll S)
{
    int n = (int)a.size();
    int left = 0;
    ll sum = 0;
    int best = n + 1;
    for (int right = 0; right < n; right++)
    {
        sum += a[right];
        while (sum >= S)
        {
            best = min(best, right - left + 1);
            sum -= a[left];
            left++;
        }
    }
    if (best == n + 1)
        return 0;
    return best;
}

/* ==================== 三、两有序数组双指针配对 ==================== */

ll max_pairs_abs_diff_at_most_one(vector<ll> a, vector<ll> b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    ll cnt = 0;
    while (i < (int)a.size() && j < (int)b.size())
    {
        ll diff = a[i] - b[j];
        if (diff < 0)
            diff = -diff;
        if (diff <= 1)
        {
            cnt++;
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return cnt;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    ll S;
    cin >> n >> S;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << longest_sum_at_most(a, S) << "\n";     // 和不超过 S 的最长区间长度
    cout << shortest_sum_at_least(a, S) << "\n";   // 和至少为 S 的最短区间长度

    vector<ll> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    cout << max_pairs_abs_diff_at_most_one(a, b) << "\n";   // |a - b| <= 1 的最大配对数

    // a = [1, 2, 3, 4], S = 6 -> 3（区间 [1, 2, 3]）；最短 2（区间 [3, 4]）
==================================================================== */
