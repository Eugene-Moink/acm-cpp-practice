/* =====================================================
前缀最值 / 前后缀分解模板（枚举分割点）

【用途】
  1. build_pref_max / build_pref_min：前缀最大 / 前缀最小数组。
  2. build_suf_max / build_suf_min：后缀最大 / 后缀最小数组。
  3. 前后缀分解骨架：枚举分割点 i，把「左边一段 + 右边一段」的答案拼起来，
     例如求 min(max(pref_max[i], suf_max[i + 1])) 这类「最小化两边较大值」的问题。

【输入】
  数组 a（vector<ll>，下标 0-based，长度 n >= 1）。
  分解场景额外传入提前定义好的 left_ans(i) / right_ans(i)（可写成 lambda）。

【输出】
  pref_max / pref_min：长度 n，pref_max[i] = max(a[0..i])，pref_min[i] = min(a[0..i])。
  suf_max / suf_min：长度 n，suf_max[i] = max(a[i..n-1])，suf_min[i] = min(a[i..n-1])。
  分解场景：按题意返回最优值（下面 split_min_of_max 返回「最小化两边较大值」的答案）。

【复杂度】
  预处理 O(n)，枚举分割点 O(n)，总体 O(n)。

【易错提醒】
  1. 前缀数组长度开 n，后缀数组长度开 n；访问 suf[i + 1] 时 i 最大只能到 n - 2。
  2. 空数组要在函数开头 return {}，否则 a[0] 越界。
  3. n == 1 时不存在合法分割点，循环区间 [0, n - 2] 为空是正确行为。
  4. 前缀和后缀的初值都取 a[0] / a[n - 1]，不要取 0 或 -INF，否则会被元素本身的符号污染。
  5. left_ans / right_ans 返回 ll，比较前统一用 ll，避免 int 与 ll 混用溢出或类型提升意外。
  6. 本文件自带 const ll INF = 1e18；与其它模板贴进同一份代码时注意删掉重复的常量定义。
===================================================== */

const ll INF = 1e18;

/* ==================== 一、前缀最大 / 前缀最小 ==================== */

vector<ll> build_pref_max(const vector<ll> &a)
{
    int n = (int)a.size();
    if (n == 0)
        return {};
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = max(pref[i - 1], a[i]);
    }
    return pref;
}

vector<ll> build_pref_min(const vector<ll> &a)
{
    int n = (int)a.size();
    if (n == 0)
        return {};
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = min(pref[i - 1], a[i]);
    }
    return pref;
}

/* ==================== 二、后缀最大 / 后缀最小 ==================== */

vector<ll> build_suf_max(const vector<ll> &a)
{
    int n = (int)a.size();
    if (n == 0)
        return {};
    vector<ll> suf(n);
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = max(suf[i + 1], a[i]);
    }
    return suf;
}

vector<ll> build_suf_min(const vector<ll> &a)
{
    int n = (int)a.size();
    if (n == 0)
        return {};
    vector<ll> suf(n);
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = min(suf[i + 1], a[i]);
    }
    return suf;
}

/* ==================== 三、枚举分割点的前后缀分解骨架 ==================== */

template <typename F>
ll split_scan(const vector<ll> &a, F left_ans, F right_ans)
{
    int n = (int)a.size();
    if (n < 2)
        return -1;
    ll ans = INF;
    for (int i = 0; i + 1 <= n - 1; i++)
    {
        ans = min(ans, max(left_ans(i), right_ans(i + 1)));
    }
    if (ans == INF)
        return -1;
    return ans;
}

ll split_min_of_max(const vector<ll> &a)
{
    vector<ll> pref = build_pref_max(a);
    vector<ll> suf = build_suf_max(a);
    int n = (int)a.size();
    if (n < 2)
        return -1;
    ll ans = INF;
    for (int i = 0; i + 1 <= n - 1; i++)
    {
        ans = min(ans, max(pref[i], suf[i + 1]));
    }
    if (ans == INF)
        return -1;
    return ans;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> pref_max = build_pref_max(a);
    vector<ll> pref_min = build_pref_min(a);
    vector<ll> suf_max = build_suf_max(a);
    vector<ll> suf_min = build_suf_min(a);
    cout << pref_max[n - 1] << " " << pref_min[n - 1] << "\n";
    cout << suf_max[0] << " " << suf_min[0] << "\n";

    cout << split_min_of_max(a) << "\n";   // 最小化「左段最大、右段最大」的较大者

    // a = [3, 1, 4, 2]：
    //   pref_max = [3, 3, 4, 4]        pref_min = [3, 1, 1, 1]
    //   suf_max  = [4, 4, 4, 2]        suf_min  = [1, 1, 2, 2]
    //   split_min_of_max -> 3（分割在 i = 1，左边 max = 3，右边 max = 4）
==================================================================== */
