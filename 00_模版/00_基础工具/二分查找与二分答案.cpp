/* =====================================================
二分查找与二分答案模板（四种场景合订）

【用途】
  1. 整数二分三写法：找第一个 >= x 的位置 / 找最后一个 <= x 的位置 / 判断 x 是否存在。
  2. lower_bound / upper_bound 的 STL 用法对照。
  3. 实数二分：for 固定 100 轮，或 while (r - l > EPS)。
  4. binary_answer(lo, hi, check)：答案具有单调性时二分答案。

【输入】
  整数二分：有序数组 a（下标 0-based）、目标值 x (ll)。
  实数二分：区间 [l, r]、精度 EPS。
  二分答案：答案区间 [lo, hi]、单参数谓词 check(ll mid)。

【输出】
  整数二分：符合条件的位置下标（找不到返回 -1）。
  实数二分：满足精度要求的实数值（double）。
  二分答案：最小可行值；无可行值返回 -1。

【复杂度】
  整数二分 / STL 对照 / 实数二分：O(log n) 或 O(轮数)。
  二分答案：O(log(值域) * check 的复杂度)。

【易错提醒】
  1. 全篇统一闭区间 l <= r，mid 写 l + (r - l) / 2，防 l + r 溢出。
  2. 二分前数组必须有序；lower_bound 返回的是「第一个不满足 a[i] < x」的位置，不是「等于 x」的位置。
  3. 返回值用 int 时数组长度不要超过 2^31，否则改用 ll。
  4. 实数二分优先用 for (int it = 0; it < 100; it++)：EPS 太小会死循环，太大会精度不够；双精度约 15 位有效数字，100 轮已远超极限。
  5. 实数二分里不要写 l + (r - l) >> 1（>> 优先级低于 +，写法错误），直接 mid = (l + r) / 2 即可。
  6. 二分答案的初始区间必须包含答案；check 里全部用 ll 运算；while 里每一轮必须真的缩区间，否则死循环。
  7. 二分答案求「最小可行值」时：可行 -> ans = mid; r = mid - 1；求「最大可行值」时把这两行改成 ans = mid; l = mid + 1。
===================================================== */

/* ==================== 一、整数二分（闭区间 l <= r） ==================== */

int lower_bound_idx(const vector<ll> &a, ll x)
{
    int l = 0, r = (int)a.size() - 1, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int upper_bound_idx(const vector<ll> &a, ll x)
{
    int l = 0, r = (int)a.size() - 1, ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] <= x)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

bool binary_exists(const vector<ll> &a, ll x)
{
    int l = 0, r = (int)a.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
            return true;
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

/* ==================== 二、STL lower_bound / upper_bound 对照 ==================== */

int stl_lower_idx(const vector<ll> &a, ll x)
{
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it == a.end())
        return -1;
    return (int)(it - a.begin());
}

int stl_upper_idx(const vector<ll> &a, ll x)
{
    auto it = upper_bound(a.begin(), a.end(), x);
    if (it == a.end())
        return -1;
    return (int)(it - a.begin());
}

ll stl_count(const vector<ll> &a, ll x)
{
    return upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x);
}

/* ==================== 三、实数二分 ==================== */

double binary_real_fixed(double l, double r, double (*check)(double))
{
    for (int it = 0; it < 100; it++)
    {
        double mid = (l + r) / 2.0;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

double binary_real_eps(double l, double r, double (*check)(double), double eps = 1e-9)
{
    while (r - l > eps)
    {
        double mid = (l + r) / 2.0;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

/* ==================== 四、二分答案框架 ==================== */

template <typename F>
ll binary_answer(ll lo, ll hi, F check)
{
    ll l = lo, r = hi, ans = -1;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    ll x;
    cin >> x;
    cout << lower_bound_idx(a, x) << " " << upper_bound_idx(a, x) << "\n";
    cout << binary_exists(a, x) << " " << stl_count(a, x) << "\n";

    // 二分答案：找最小的 k 使 k * (k + 1) / 2 >= x
    auto check_int = [&](ll mid) -> bool {
        return mid * (mid + 1) / 2 >= x;
    };
    cout << binary_answer(0, (ll)2e9, check_int) << "\n";

    // 实数二分：check(t) 是「t 是否满足条件」，二分收敛到满足条件的最小 t
    // 想改成「找满足条件的最大 t」，把两个函数里的 r = mid / l = mid 对调即可
    auto check_real = [](double t) -> bool {
        return t * t >= 2.0;
    };
    printf("%.10f\n", binary_real_fixed(0.0, 2.0, check_real));
    printf("%.10f\n", binary_real_eps(0.0, 2.0, check_real, 1e-10));

    // a = [1, 3, 3, 5], x = 3 时：
    //   lower_bound_idx -> 1     upper_bound_idx -> 2
    //   stl_count       -> 2     binary_exists   -> 1
==================================================================== */
