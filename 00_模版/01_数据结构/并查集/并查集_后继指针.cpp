/* =====================================================
并查集_后继指针

【用途】
  把并查集当「下一个未占用位置」的指针用：find(x) 返回 ≥ x 的第一个还没被认领的下标。
  典型场景：离线倒序处理区间赋值（后写的覆盖先写的）、座位 / 资源分配、删除元素后找后继、
            区间染色、「每个位置只处理一次」的均摊优化。
【输入】
  NextDSU(n)：下标取值 1..n，n + 1 是哨兵（表示「后面没有空位了」）。
  occupy(l, r, fn)：把 [l, r] 内每个还没被认领的位置交给 fn 处理一次。
【输出】
  find(x) 返回下标；occupy 通过回调返回位置。
  offline_range_assign 返回每个位置最终的值（数组 init 为初值，Ops 按时间顺序给出）。
【复杂度】
  每次 find 均摊 O(α(n))；整个 occupy([1, n]) 总共 O(n α(n))，因为每个位置只会被认领一次。
【易错提醒】
  1. nxt 要开 n + 2 且 nxt[n + 1] = n + 1，否则 pos + 1 越界。
  2. 认领 pos 之后必须先 nxt[pos] = find(pos + 1)，再让 pos = find(pos)（等价于 find(pos + 1)）。
  3. 离线倒序是关键：从最后一次操作往前扫，某个位置第一次被认领时的值就是最终值。
  4. find 必须带路径压缩，否则链式退化到 O(n) 每次。
  5. 它是「找下一个空位」不是「区间染色」，区间赋值要 while (pos <= r) 逐个位置认领。
===================================================== */
struct NextDSU
{
    vector<int> nxt;

    explicit NextDSU(int n)
    {
        nxt.assign(n + 2, 0);
        for (int i = 1; i <= n + 1; i++)
        {
            nxt[i] = i;
        }
    }

    int find(int x)
    {
        while (nxt[x] != x)
        {
            nxt[x] = nxt[nxt[x]];
            x = nxt[x];
        }
        return x;
    }

    void occupy(int l, int r, const function<void(int)> &fn)
    {
        for (int pos = find(l); pos <= r; pos = find(pos))
        {
            fn(pos);
            nxt[pos] = find(pos + 1);
        }
    }
};

struct RangeAssignOp
{
    int l, r;
    ll v;
};

vector<ll> offline_range_assign(int n, const vector<RangeAssignOp> &ops, vector<ll> init)
{
    NextDSU dsu(n);
    for (int i = (int)ops.size() - 1; i >= 0; i--)
    {
        int l = ops[i].l, r = ops[i].r;
        ll v = ops[i].v;
        dsu.occupy(l, r, [&](int pos)
                  { init[pos] = v; });
    }
    return init;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<RangeAssignOp> ops(q);
    for (int i = 0; i < q; i++)
        cin >> ops[i].l >> ops[i].r >> ops[i].v;

    vector<ll> ans = offline_range_assign(n, ops, a);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];

    // 纯粹找下一个空位：
    // NextDSU dsu(n);
    // int p = dsu.find(l);
   ==================================================================== */
