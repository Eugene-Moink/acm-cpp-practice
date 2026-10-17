/* =====================================================
前缀和与差分（一维 + 二维）

【用途】
  基础：一维前缀和 / 一维差分 / 二维前缀和 / 二维差分（区间加、子矩阵加）。
  变体（文末五～七节）：同余前缀和计数（子段和整除 k 的个数 / 最长）、
                        前缀和 + 哈希表计数子段和 = K、匹配位置前缀和（区间内出现次数）。
【输入】
  见各分节内的读入片段：数组长度与元素、查询区间 [l, r]、修改区间与增量。
【输出】
  区间和 / 子矩阵和 / 全部修改完成后还原出的数组；变体节各函数返回计数 / 长度。
【复杂度】
  预处理 O(n)（二维 O(H·W)），单次查询与单次修改 O(1)；
  变体节为 O(n)（哈希表计数）或 O(n·m)（朴素匹配，大文本改 KMP）。
【易错提醒】
  1. 前缀和数组开 n + 1 并令 pref[0] = 0。
  2. 差分数组要开 n + 2，因为会访问 diff[R + 1]。
  3. 二维差分要改四个角，数组开 (H + 2) × (W + 2)。
  4. 二维前缀和公式符号：+ 上 + 左 - 左上，别抄错。
  5. 区间一律是闭区间 [l, r]。
  6. 同余前缀和：sum(l..r) % k == 0 ⟺ pref[r] % k == pref[l-1] % k；
     计数桶必须先令 cnt[0] = 1，负数取模用 (x % k + k) % k 归正。
  7. 前缀和 + 哈希表只能统计「和为定值」的子段；有负数时不能用双指针 / 滑窗代替。
===================================================== */
void solve()
{
    // ==================== 一维前缀和 ====================
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    // 查询区间 [l, r] 的和（1-based）
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << "\n";

    // ==================== 一维差分 ====================
    vector<ll> diff(n + 2, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int L, R;
        ll val;
        cin >> L >> R >> val;
        diff[L] += val;
        diff[R + 1] -= val;
    }

    vector<ll> restored(n, 0);
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += diff[i];
        restored[i] = a[i] + cur;
    }
    for (int i = 0; i < n; i++)
        cout << restored[i] << " ";
    cout << "\n";

    // ==================== 二维前缀和 ====================
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> grid(H, vector<ll>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> grid[i][j];

    vector<vector<ll>> pref2(H + 1, vector<ll>(W + 1, 0));
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            pref2[i][j] = pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    // 查询子矩阵 (x1, y1) 到 (x2, y2) 的和（1-based）
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << pref2[x2][y2] - pref2[x1 - 1][y2] - pref2[x2][y1 - 1] + pref2[x1 - 1][y1 - 1] << "\n";

    // ==================== 二维差分 ====================
    vector<vector<ll>> diff2(H + 2, vector<ll>(W + 2, 0));
    int q2;
    cin >> q2;
    while (q2--)
    {
        int X1, Y1, X2, Y2;
        ll val;
        cin >> X1 >> Y1 >> X2 >> Y2 >> val;
        diff2[X1][Y1] += val;
        diff2[X1][Y2 + 1] -= val;
        diff2[X2 + 1][Y1] -= val;
        diff2[X2 + 1][Y2 + 1] += val;
    }

    vector<vector<ll>> ans2(H, vector<ll>(W, 0));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            ans2[i][j] = diff2[i][j];
            if (i > 0)
                ans2[i][j] += ans2[i - 1][j];
            if (j > 0)
                ans2[i][j] += ans2[i][j - 1];
            if (i > 0 && j > 0)
                ans2[i][j] -= ans2[i - 1][j - 1];
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
            cout << ans2[i][j] << " ";
        cout << "\n";
    }
}

/* ==================== 五、同余前缀和：子段和整除 k 的计数 / 最长 ====================
 * 原理：sum(l..r) % k == 0  ⟺  pref[r] % k == pref[l-1] % k。
 * 计数版把每个前缀余数丢进桶，遇到相同余数就累加之前的出现次数；
 * 最长版只记每个余数第一次出现的下标。
 * 对应题：洛谷 P8649 k 倍区间 / P3131 / CF 2276C。
 * ================================================================= */
ll count_subarrays_divisible_by_k(const vector<ll> &a, ll k)
{
    if (k == 0)
    {
        return 0;
    }
    unordered_map<ll, ll> cnt;
    cnt[0] = 1;                          // 空前缀，等价于「从第 1 个元素开始的子段」
    ll sum = 0, ans = 0;
    for (ll x : a)
    {
        sum = ((sum + x) % k + k) % k;   // 负数归正
        ans += cnt[sum];
        cnt[sum]++;
    }
    return ans;
}

ll longest_subarray_divisible_by_k(const vector<ll> &a, ll k)
{
    if (k == 0)
    {
        return 0;
    }
    unordered_map<ll, ll> first;
    first[0] = 0;                        // 前缀下标 0（空前缀）在位置 0
    ll sum = 0, ans = 0;
    for (int i = 1; i <= (int)a.size(); i++)
    {
        sum = ((sum + a[i - 1]) % k + k) % k;
        if (first.count(sum))
        {
            ans = max(ans, (ll)i - first[sum]);
        }
        else
        {
            first[sum] = i;
        }
    }
    return ans;
}

/* ==================== 六、前缀和 + 哈希表：子段和恰好等于 K ====================
 * 每读到一个前缀和 sum，就去查之前有多少个前缀和等于 sum - K。
 * 有负数也能做（不能用双指针 / 滑窗）。对应题：ABC233 D、洛谷 P3131 类。
 * ======================================================================= */
ll count_subarray_sum_eq_k(const vector<ll> &a, ll k)
{
    unordered_map<ll, ll> cnt;
    cnt[0] = 1;
    ll sum = 0, ans = 0;
    for (ll x : a)
    {
        sum += x;
        auto it = cnt.find(sum - k);
        if (it != cnt.end())
        {
            ans += it->second;
        }
        cnt[sum]++;
    }
    return ans;
}

/* ==================== 七、匹配位置前缀和：区间内出现次数 ====================
 * 先把「每个匹配起点」标成 1，再做前缀和；查询区间 [l, r] 内的匹配数 = pre[r+1] - pre[l]。
 * 文本很大时把 text.compare 换成 KMP / Z 函数，否则退化成 O(n·m)。
 * 对应题：模式串在区间内的出现次数类（old/子串出现次数.cpp）。
 * ====================================================================== */
ll count_matches_in_range(const string &text, const string &pat, int l, int r)
{
    int n = (int)text.size(), m = (int)pat.size();
    if (m == 0 || m > n)
    {
        return 0;
    }

    vector<int> pre(n + 1, 0);           // pre[i] = 起点 < i 的匹配个数
    for (int i = 0; i + m <= n; i++)
    {
        pre[i + 1] = pre[i] + (text.compare(i, m, pat) == 0 ? 1 : 0);
    }

    l = max(l, 0);
    r = min(r, n - m);
    if (l > r)
    {
        return 0;
    }
    return pre[r + 1] - pre[l];
}