/*
 * 归并排序 / 求逆序对
 *
 * 【用途】对序列做稳定的归并排序；并可在合并过程中顺便统计逆序对个数（满足 i < j 且 a[i] > a[j] 的数对）。
 * 【输入】数组 a（vector<ll>，下标 0-based，元素可重复）、闭区间端点 l、r
 * 【输出】merge_sort_count 返回 [l, r] 内的逆序对个数（ll）；merge_sort 原地排好序、无返回值
 * 【复杂度】时间 O(n log n)，空间 O(n)（每次合并临时开一个 tmp 数组，递归栈 O(log n) 不另计）
 * 【易错提醒】1. 答案必须用 ll：逆序对最多 n(n-1)/2，n = 2e5 时约 2e10，用 int 会溢出；
 *             2. 必须先递归左右两半、再合并统计，顺序颠倒会漏算所有跨区间的逆序对；
 *             3. 只有 a[j] < a[i]（严格小于）才计逆序对，相等时走 a[i] <= a[j] 这一支，不计数；
 *             4. 计数式是 ans += mid - i + 1：此刻 a[i..mid] 全都大于 a[j]，个数正好是 mid - i + 1；
 *             5. 合并完必须把 tmp 写回 a[l..r]，漏写会让上一层拿到未排序的数据，逆序对也会少算；
 *             6. 调用区间是 [0, n - 1]，l >= r 时函数直接返回 0，n = 0 或 1 都不需要额外特判。
 *
 * 多组数据：没有全局变量，函数自己返回答案，反复调用即可。
 */

/* ==================== 一、归并排序 + 统计逆序对 ==================== */

ll merge_sort_count(vector<ll> &a, int l, int r)
{
    if (l >= r)
    {
        return 0;
    }

    int mid = l + (r - l) / 2;

    ll ans = merge_sort_count(a, l, mid);
    ans += merge_sort_count(a, mid + 1, r);

    vector<ll> tmp;
    tmp.reserve(r - l + 1);

    int i = l;
    int j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp.push_back(a[i]);
            i++;
        }
        else
        {
            ans += mid - i + 1;
            tmp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        tmp.push_back(a[i]);
        i++;
    }

    while (j <= r)
    {
        tmp.push_back(a[j]);
        j++;
    }

    for (int k = 0; k < (int)tmp.size(); k++)
    {
        a[l + k] = tmp[k];
    }

    return ans;
}

/* ==================== 二、纯归并排序（不计数；a[i] <= a[j] 这一支保证稳定） ==================== */

void merge_sort(vector<ll> &a, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int mid = l + (r - l) / 2;

    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    vector<ll> tmp;
    tmp.reserve(r - l + 1);

    int i = l;
    int j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp.push_back(a[i]);
            i++;
        }
        else
        {
            tmp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        tmp.push_back(a[i]);
        i++;
    }

    while (j <= r)
    {
        tmp.push_back(a[j]);
        j++;
    }

    for (int k = 0; k < (int)tmp.size(); k++)
    {
        a[l + k] = tmp[k];
    }
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> b = a;                            // 求逆序对会打乱数组，两个都想要就先备份
    ll cnt = merge_sort_count(b, 0, n - 1);
    cout << cnt << "\n";                         // 逆序对个数，例如 [5, 3, 1] -> 3

    merge_sort(a, 0, n - 1);                     // 纯归并排序（升序）
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i + 1 == n];

    // 求「逆序对」也可以先离散化再统计；离散化见 00_基础工具\离散化.cpp
    ==================================================================== */
