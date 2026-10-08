/*
 * 【用途】堆与优先队列（三个互不依赖的片段）：priority_queue 四种声明写法、对顶堆动态中位数、反悔贪心（带时间戳偏移）。
 * 【输入】分节一的堆对象由使用方自行 push；MedianHeap 用 insert(x) 逐个插入 ll；
 *         max_net_profit(v, k, chosen) 传入价值数组 v 与容量 k。
 * 【输出】heap_* 为可直接使用的堆对象；MedianHeap::median() 返回当前中位数（偶数个时返回偏小的一侧）；
 *         max_net_profit 返回最大净收益之和，chosen 按净值升序给出被选中物品的原始价值。
 * 【复杂度】priority_queue 单次 push / pop 为 O(log n)，取堆顶 O(1)；
 *           MedianHeap 每次 insert 为 O(log n)，median 为 O(1)；
 *           max_net_profit 为 O(n log k) 时间、O(k) 空间。
 * 【易错提醒】1) priority_queue 默认是大根堆，小根堆必须写 greater<T>，且必须补上底层容器参数；
 *             2) 自定义比较器返回 true 表示 x 的优先级低于 y，语义与 sort 的 cmp 相反，别写反；
 *             3) 堆为空时 top() / median() 是未定义行为，调用前保证非空；
 *             4) 对顶堆每次 insert 后要立刻平衡，且只把元素从较大的那侧搬到较小的那侧；
 *             5) 带时间戳偏移时堆里存的是 value - t，出堆想拿原始值必须 net + t 还原，两种量不要混用。
 */

/* ==================== 一、priority_queue 的四种声明写法 ==================== */
priority_queue<int> heap_max;
priority_queue<int, vector<int>, greater<int>> heap_min;
priority_queue<pair<ll, int>> heap_pair;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> heap_pair_asc;

struct CmpSecond
{
    bool operator()(const pair<ll, int> &x, const pair<ll, int> &y) const
    {
        return x.second > y.second;
    }
};

priority_queue<pair<ll, int>, vector<pair<ll, int>>, CmpSecond> heap_custom;

/* ==================== 二、对顶堆动态中位数 ====================
 * small 是大根堆，存较小的一半；large 是小根堆，存较大的一半；
 * 平衡后约定 small.size() == large.size() 或 large.size() + 1，于是中位数就是 small.top()。
 * ======================================================== */
struct MedianHeap
{
    priority_queue<ll> small;
    priority_queue<ll, vector<ll>, greater<ll>> large;

    void balance()
    {
        while ((int)small.size() > (int)large.size() + 1)
        {
            large.push(small.top());
            small.pop();
        }
        while ((int)large.size() > (int)small.size())
        {
            small.push(large.top());
            large.pop();
        }
    }

    void insert(ll x)
    {
        if (small.empty() || x <= small.top())
            small.push(x);
        else
            large.push(x);
        balance();
    }

    ll median() const
    {
        return small.top();
    }
};

/* ==================== 三、反悔贪心：入堆存 value - t，出堆 + t 还原 ====================
 * 示例问题（容量限制下的收益贪心）：n 个物品依次在时刻 t = 1, 2, ..., n 出现，第 i 个物品价值 v[i]；
 * 若在时刻 t 取用它，净收益为 v[i] - t（时间惩罚）；最多只能取 k 个，求最大净收益之和。
 * 做法：从左到右把 (v[i] - t, t) 压入小根堆，堆大小超过 k 就弹出堆顶（净值最小的那个，即反悔掉它），
 *       这样堆里始终保留「到目前为止净值最大的 k 个」；出堆时用 net + t 还原原始价值 v[i]。
 * ================================================================================ */
ll max_net_profit(const vector<ll> &v, int k, vector<ll> &chosen)
{
    chosen.clear();
    int n = (int)v.size();
    if (k <= 0 || n == 0)
        return 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        ll t = i + 1;
        pq.push({v[i] - t, (int)t});
        if ((int)pq.size() > k)
            pq.pop();
    }

    ll ans = 0;
    while (!pq.empty())
    {
        ll net = pq.top().first;
        ll t = pq.top().second;
        pq.pop();
        ans += net;
        chosen.push_back(net + t);
    }
    return ans;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;

    MedianHeap mh;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mh.insert(x);
        cout << "当前中位数 = " << mh.median() << "\n";
    }

    heap_max.push(3);
    heap_min.push(3);
    heap_pair.push({5, 1});
    heap_pair_asc.push({5, 1});
    heap_custom.push({5, 1});
    cout << heap_max.top() << " " << heap_min.top() << " " << heap_custom.top().second << "\n";

    int k;
    cin >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<ll> chosen;
    ll best = max_net_profit(v, k, chosen);
    cout << best << "\n";
    for (ll x : chosen)
        cout << x << " ";
    cout << "\n";
   ==================================================================== */
