/*
 * 【用途】树状数组（区间修改 + 单点查询）：本质是对差分数组建 BIT，实现区间加与单点求值。
 * 【输入】BITDiff(int n) 传入数组长度；range_add(l, r, v) 把 a[l .. r] 每个元素加 v；
 *         point_query(i) 查询 a[i] 的当前值。
 * 【输出】point_query(i) 返回第 i 个元素的当前值，即差分数组的前缀和。
 * 【复杂度】range_add / point_query 均为 O(log n)；空间 O(n)。
 * 【易错提醒】1) 下标必须 1-based，l >= 1 且 r <= n，传 0 进去会让 i += i & -i 原地死循环；
 *             2) 内部数组按 n + 2 的容量开（这里多留了余量），因为 range_add 会写 r + 1，最大取到 n + 1，容量不足会越界；
 *             3) 前缀和的下标要到 n + 1，所以 add 的循环上界是 n + 1 而不是 n，写成 n 会让 r == n 时那次 -v 丢失；
 *             4) 初始值用 range_add(i, i, a[i]) 逐位写入，或直接在差分数组上建树；
 *             5) 本模板只支持区间改 + 单点查，要区间查需再维护一棵普通 BIT。
 */
struct BITDiff
{
    int n;
    vector<ll> tr;

    BITDiff(int n = 0) : n(n), tr(n + 3, 0)
    {
    }

    void add(int i, ll v)
    {
        for (; i <= n + 1; i += i & -i)
            tr[i] += v;
    }

    void range_add(int l, int r, ll v)
    {
        add(l, v);
        add(r + 1, -v);
    }

    ll point_query(int i) const
    {
        ll res = 0;
        for (; i > 0; i -= i & -i)
            res += tr[i];
        return res;
    }
};

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, q;
    cin >> n >> q;

    BITDiff bit(n);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        bit.range_add(i, i, x);
    }

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            ll v;
            cin >> l >> r >> v;
            bit.range_add(l, r, v);
        }
        else
        {
            int i;
            cin >> i;
            cout << bit.point_query(i) << "\n";
        }
    }
   ==================================================================== */
