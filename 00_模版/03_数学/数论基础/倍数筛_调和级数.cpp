/* =====================================================
倍数筛_调和级数

【用途】
  预处理 cnt[d] = 输入中有多少个数是 d 的倍数，总复杂度 O(V log V)（调和级数 Σ V/d）。
  派生用法：① 求「最多取 k 个数时的最大公因数」；② 统计每个数的因子出现次数；
            ③ 求区间内某数的倍数个数；④ 配合容斥求「gcd 恰好为 d」的配对/子集数。
【输入】
  a：整数数组；V：值域上界（一般取 max(a)，不要用 n 代替）。
  freq：也可以直接传频率数组（元素值域很小时更省一次遍历）。
【输出】
  multiple_count：cnt[1..V]，cnt[d] 是 d 的倍数的出现次数。
  max_divisor_for_k：ans[k] = 从 a 中取 k 个数时能得到的最大公因数（全 0 表示取不到 k 个）。
【复杂度】
  倍数筛 O(V log V)；max_divisor_for_k 在倍数筛基础上再 O(V + n·(V/d 总增量))，实际约 O(V + n)。
【易错提醒】
  1. V 必须是「最大元素值」而不是 n，否则下标越界或结果缺失。
  2. 内层从 m = d 开始（不能从 2d 开始），否则漏掉 d 自身这个倍数。
  3. Σ_{d=1..V} V/d ≈ V ln V；V = 1e7 时约 1.6e8 次加法，注意时限与常数。
  4. cnt[d] 是「是 d 的倍数」的个数，不是「gcd 恰好为 d」；要恰好为 d 必须从大到小减掉 cnt[2d]、cnt[3d]…
  5. 值可能为 0 或负数：0 是所有数的倍数、负数只取绝对值，题意不保证时先过滤。
===================================================== */
vector<int> multiple_count(const vector<int> &a, int V)
{
    vector<int> freq(V + 1, 0);
    for (int x : a)
    {
        if (x >= 1 && x <= V)
        {
            freq[x]++;
        }
    }

    vector<int> cnt(V + 1, 0);
    for (int d = 1; d <= V; d++)
    {
        for (int m = d; m <= V; m += d)
        {
            cnt[d] += freq[m];
        }
    }
    return cnt;
}

/* 派生：ans[k] = 选 k 个数能拿到的最大公因数
 * 从大到小扫 d，cnt[d] 就是「gcd 至少为 d」最多能选多少个数；
 * 若 cnt[d] 超过当前已确定的最大 k，则 (max_k, cnt[d]] 这些 k 的答案都是 d。*/
vector<int> max_divisor_for_k(const vector<int> &a, int V)
{
    int n = (int)a.size();
    vector<int> freq(V + 1, 0);
    for (int x : a)
    {
        if (x >= 1 && x <= V)
        {
            freq[x]++;
        }
    }

    vector<int> cnt(V + 1, 0);
    for (int d = 1; d <= V; d++)
    {
        for (int m = d; m <= V; m += d)
        {
            cnt[d] += freq[m];
        }
    }

    vector<int> ans(n + 1, 0);
    int max_k = 0;
    for (int d = V; d >= 1 && max_k < n; d--)
    {
        if (cnt[d] > max_k)
        {
            for (int k = max_k + 1; k <= cnt[d] && k <= n; k++)
            {
                ans[k] = d;
            }
            max_k = cnt[d];
        }
    }
    return ans;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<int> a(n);
    int V = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        V = max(V, a[i]);
    }

    vector<int> cnt = multiple_count(a, V);
    cout << "是 4 的倍数的个数 = " << cnt[4] << "\n";

    vector<int> ans = max_divisor_for_k(a, V);
    for (int k = 1; k <= n; k++)
        cout << ans[k] << "\n";
   ==================================================================== */
