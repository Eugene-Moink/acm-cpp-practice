/*
 * 【用途】树状数组（单点修改 + 区间查询）：维护可加性信息的前缀和，下标 1-based。
 * 【输入】BIT(int n) 传入元素个数；add(i, v) 把第 i 个元素加上 v；
 *         sum(i) 查询前缀和；range_sum(l, r) 查询区间和。
 * 【输出】sum(i) 返回 a[1] + a[2] + ... + a[i]（i <= 0 时返回 0）；
 *         range_sum(l, r) 返回 a[l] + ... + a[r]，l > r 时返回 0。
 * 【复杂度】add / sum / range_sum 均为 O(log n)；空间 O(n)。
 * 【易错提醒】1) 下标必须 1-based，传 0 进去会让 i += i & -i 原地死循环；
 *             2) sum(i) 要求 0 <= i <= n，越界访问 tr 是未定义行为；
 *             3) 区间和是 sum(r) - sum(l - 1)，减的是 l - 1 而不是 l；
 *             4) 答案用 ll 存放，多次修改后前缀和容易溢出 int；
 *             5) 本模板只做单点改 + 区间查，要「区间改 + 区间查」需要两棵 BIT。
 */
struct BIT
{
    int n;
    vector<ll> tr;

    BIT(int n = 0) : n(n), tr(n + 1, 0)
    {
    }

    void add(int i, ll v)
    {
        for (; i <= n; i += i & -i)
            tr[i] += v;
    }

    ll sum(int i) const
    {
        ll res = 0;
        for (; i > 0; i -= i & -i)
            res += tr[i];
        return res;
    }

    ll range_sum(int l, int r) const
    {
        if (l > r)
            return 0;
        return sum(r) - sum(l - 1);
    }
};

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, q;
    cin >> n >> q;

    BIT bit(n);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        bit.add(i, x);
    }

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i;
            ll v;
            cin >> i >> v;
            bit.add(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << bit.range_sum(l, r) << "\n";
        }
    }
   ==================================================================== */
