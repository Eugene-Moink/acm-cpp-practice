/*
 * 快速选择 / 第 k 小
 *
 * 【用途】在无序数组中求第 k 小的元素，不需要把整个数组排好序。
 * 【输入】数组 a（vector<ll>，手写版会被原地打乱）、k（下标从 0 开始：k = 0 求最小值，k = n - 1 求最大值）
 * 【输出】第 k 小的元素值（ll，重复元素按位置计数，即求排序后 a[k]）
 * 【复杂度】平均 O(n)、最坏 O(n^2)（Hoare 分区取中点为基准，有序数据不会退化）；库函数版 nth_element 平均 O(n)、最坏 O(n log n)
 * 【易错提醒】1. k 是 0-based，题目给的是 1-based（第 k 小、k >= 1）要先 k--；
 *             2. 分区基准必须取 a[(l + r) >> 1]：取 a[l] 或 a[r] 在已排序数据上会退化成 O(n^2)；
 *             3. 每次只在包含 k 的那一侧继续（本模板写成迭代版，等价于「只递归一侧」），两侧都处理就成快速排序了；
 *             4. 必须用 Hoare 式分区（i <= j 才交换，交换后 i++、j--），且要处理与基准相等的元素，否则重复元素多时同样退化；
 *             5. 函数会改变数组内容（元素被交换过），后续还要用原序就先备份；
 *             6. 调用前保证 0 <= k < n：k 越界时 a[k] 是未定义行为，nth_element 版本同样要求 k 合法。
 *
 * 多组数据：函数自身无全局状态，反复调用即可（每次调用前自行准备好数组）。
 */

/* ==================== 一、手写 Hoare 分区版（nth_element 等价，中等数据上常数更小） ==================== */

ll quick_select(vector<ll> &a, int k)
{
    int l = 0;
    int r = (int)a.size() - 1;

    while (l < r)
    {
        int i = l;
        int j = r;
        ll pivot = a[(l + r) >> 1];

        while (i <= j)
        {
            while (a[i] < pivot)
            {
                i++;
            }

            while (a[j] > pivot)
            {
                j--;
            }

            if (i <= j)
            {
                swap(a[i], a[j]);
                i++;
                j--;
            }
        }

        if (k <= j)
        {
            r = j;
        }
        else if (k >= i)
        {
            l = i;
        }
        else
        {
            break;
        }
    }

    return a[k];
}

/* ==================== 二、库函数版 nth_element（一行完成分区，参数按值传递所以不动原数组） ==================== */

ll kth_smallest_stl(vector<ll> a, int k)
{
    nth_element(a.begin(), a.begin() + k, a.end());
    return a[k];
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, k;
    cin >> n >> k;                               // k 是 0-based；题目若给 1-based 就 k--
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> b = a;                            // quick_select 会打乱 a，先备份
    cout << quick_select(a, k) << "\n";          // 第 k 小

    cout << kth_smallest_stl(b, k) << "\n";      // 库函数版，b 按值传入，外面不受影响

    // 例：a = [3, 1, 4, 1, 5]，k = 2 -> 两版都输出 3（排序后 [1, 1, 3, 4, 5] 的下标 2）
    // 只要第 k 小就选本模板；要整个数组有序、或要「第 k 小的下标之和」这类附加信息，直接用 sort
    ==================================================================== */
