/*
 * 排序 / 自定义比较器
 *
 * 【用途】四种常用排序写法合订：① 结构体内部 operator< 多关键字排序；② sort + lambda 比较器；
 *         ③ sort + greater 降序；④ pair 的默认比较规则（先 first 后 second）。
 * 【输入】待排序的数组（vector<ll> / vector<SortItem> / vector<pair<ll, ll>>）
 * 【输出】原地排好序，各函数均无返回值
 * 【复杂度】均为 O(n log n) 时间、O(log n) 递归栈空间（额外空间视 sort 的具体实现而定）
 * 【易错提醒】1. 比较器必须是严格弱序：只写 < 或 >，写成 <= / >= 会在运行期越界崩溃（典型表现是 segfault 或死循环）；
 *             2. 结构体内部的 operator< 必须加 const 修饰、参数用 const 引用，否则 sort 编译不过；
 *             3. 多关键字时注意第二关键字的方向：a 升序 + b 降序要先比 a，a 相等时返回 b > o.b；
 *             4. 两个元素「相等」时比较器两个方向都要返回 false，且 sort 不稳定，不能依赖相等元素的相对顺序；
 *             5. pair 默认比较是字典序（先 first 升序，first 相同再 second 升序），想改方向必须自己写比较器；
 *             6. greater<ll> 要求类型支持 >，结构体要用它得自己重载 operator>，一般改用 lambda 更省事。
 *
 * 多组数据：排序是原地操作，无全局状态。
 */

/* ==================== 一、结构体内部 operator<（先按 a 升序，a 相同按 b 降序） ==================== */

struct SortItem
{
    ll a;
    ll b;

    bool operator<(const SortItem &o) const
    {
        if (a != o.a)
        {
            return a < o.a;
        }
        return b > o.b;
    }
};

/* ==================== 二、sort + lambda 比较器（与上面 operator< 等价，临时改规则时更方便） ==================== */

void sort_by_lambda(vector<SortItem> &v)
{
    sort(v.begin(), v.end(), [](const SortItem &x, const SortItem &y)
    {
        if (x.a != y.a)
        {
            return x.a < y.a;
        }
        return x.b > y.b;
    });
}

/* ==================== 三、sort + greater 降序（greater<ll> 可简写成 greater<>，C++14 起自动推导） ==================== */

void sort_desc(vector<ll> &a)
{
    sort(a.begin(), a.end(), greater<ll>());
}

/* ==================== 四、pair 默认比较：先 first 升序，first 相同再 second 升序 ==================== */

void sort_pairs_default(vector<pair<ll, ll>> &v)
{
    sort(v.begin(), v.end());
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;

    vector<SortItem> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].a >> v[i].b;

    sort(v.begin(), v.end());                    // 用结构体内部的 operator<
    // sort_by_lambda(v);                        // 用 lambda 比较器，效果同上

    for (int i = 0; i < n; i++)
        cout << v[i].a << " " << v[i].b << "\n";

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort_desc(a);                                // 降序

    vector<pair<ll, ll>> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort_pairs_default(p);                       // pair 默认按 (first, second) 字典序升序

    // 想要「first 升序 + second 降序」就得自己写比较器：
    sort(p.begin(), p.end(), [](const pair<ll, ll> &x, const pair<ll, ll> &y)
    {
        if (x.first != y.first)
        {
            return x.first < y.first;
        }
        return x.second > y.second;
    });
    ==================================================================== */
