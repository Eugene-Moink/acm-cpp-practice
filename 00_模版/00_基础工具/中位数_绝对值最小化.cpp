/* =====================================================
中位数 / 绝对值最小化模板

【用途】
  1. min_abs_sum：求 Σ|a_i − x| 的最小值，x 任意（答案在 a 的中位数处取到）。
  2. pairwise_abs_sum：O(n log n) 求 Σ_{i<j} |a_i − a_j|。

【输入】
  min_abs_sum：数组 a（vector<ll>，可为负数，长度可奇可偶）。
  pairwise_abs_sum：数组 a（vector<ll>）。

【输出】
  min_abs_sum：最小的 Σ|a_i − x|（ll）。
  pairwise_abs_sum：所有下标对 (i, j)（i < j）的 |a_i − a_j| 之和（ll）。

【复杂度】
  min_abs_sum：O(n log n)（排序），求和 O(n)。
  pairwise_abs_sum：O(n log n)（排序 + 前缀和）。

【易错提醒】
  1. 函数内部会先把 a 排序，传入的数组会被修改；需要保留原序请先复制一份。
  2. 偶数个元素时取左中位数 a[(n-1)/2] 或右中位数 a[n/2] 结果完全相同：中间两个数之间的任意 x 都能取到最小值，不用纠结取哪个。
  3. min_abs_sum 遍历累加时用 a[i] - med，不要写 med - a[i]，否则负数会算反（正确写法是取绝对值或统一成 a[i] - med 再 abs）。
  4. pairwise_abs_sum 的和可能很大：n = 2e5、值域 1e9 时约 2e19，超过 ll 上限（约 9.2e18）时要改用 __int128。
  5. pairwise_abs_sum 的前缀和必须开 ll，累加前把 a[i] 转成 ll。
  6. 中位数与「平均数的绝对值最小化」不是一回事：最小化平方和才取平均数。
===================================================== */

/* ==================== 一、Σ|a_i − median| 的最小值 ==================== */

ll min_abs_sum(vector<ll> a)
{
    int n = (int)a.size();
    if (n == 0)
        return 0;
    sort(a.begin(), a.end());
    ll med = a[n / 2];
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll diff = a[i] - med;
        if (diff < 0)
            diff = -diff;
        sum += diff;
    }
    return sum;
}

/* ==================== 二、Σ_{i<j}|a_i − a_j| ==================== */

ll pairwise_abs_sum(vector<ll> a)
{
    int n = (int)a.size();
    if (n < 2)
        return 0;
    sort(a.begin(), a.end());
    vector<ll> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] = pre[i] + a[i];
    }
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        total += a[i] * i - pre[i];
    }
    return total;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << min_abs_sum(a) << "\n";        // 选一个 x 使 Σ|x − a_i| 最小，输出最小值
    cout << pairwise_abs_sum(a) << "\n";   // 所有两两差的绝对值之和

    vector<ll> b = a;
    sort(b.begin(), b.end());
    cout << b[(n - 1) / 2] << " " << b[n / 2] << "\n";   // 偶数时两个中位数的绝对值代价相同

    // a = [1, 2, 3, 10]：
    //   min_abs_sum      -> med = 3，1 + 1 + 0 + 7 = 9（取 med = 2 也是 9）
    //   pairwise_abs_sum -> 1 + 2 + 9 + 1 + 8 + 7 = 28
==================================================================== */
