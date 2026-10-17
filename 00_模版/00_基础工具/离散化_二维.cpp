/* =====================================================
离散化_二维

【用途】
  把 n 个矩形的 4 条边界坐标分别压缩成 1..nx / 1..ny 的紧凑下标，
  在「压缩格」上做覆盖标记，解决矩形并面积、矩形并周长、扫描线前处理等问题。
【输入】
  Rect{ x1, y1, x2, y2 }：矩形两条对角，允许 x1 > x2 / y1 > y2，add() 内部会交换成左下右上。
【输出】
  rect_union_area 返回所有矩形覆盖的面积之和（ll）。
  Disc2D::build 之后：xs / ys 为去重升序坐标，ix(x) / iy(y) 返回 0-based 压缩下标，nx() / ny() 返回点数。
【复杂度】
  离散化 O(n log n)，标记 O(n · nx · ny) 最坏，面积求和 O(nx · ny)。
【易错提醒】
  1. 压缩网格是「格」不是「点」：第 i 行覆盖 [xs[i], xs[i+1])，所以下标只用到 nx-2 / ny-2。
  2. 标记矩形用半开区间 [ix(x1), ix(x2)) × [iy(y1), iy(y2))，右端点不要再 +1。
  3. 面积 = (xs[i+1]-xs[i]) * (ys[j+1]-ys[j])，必须用压缩后的相邻坐标差。
  4. 坐标可以为负、可以重复；重复坐标去重后只留一个，不会影响面积。
  5. 只关心相对大小，不关心真实跨度时也可以用这个套路做矩形并周长。
===================================================== */
struct Rect
{
    ll x1, y1, x2, y2;
};

struct Disc2D
{
    vector<ll> xs, ys;

    void add(const Rect &r)
    {
        ll xl = min(r.x1, r.x2), xr = max(r.x1, r.x2);
        ll yl = min(r.y1, r.y2), yr = max(r.y1, r.y2);
        xs.push_back(xl);
        xs.push_back(xr);
        ys.push_back(yl);
        ys.push_back(yr);
    }

    void build()
    {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
    }

    int ix(ll x) const
    {
        return (int)(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
    }

    int iy(ll y) const
    {
        return (int)(lower_bound(ys.begin(), ys.end(), y) - ys.begin());
    }

    int nx() const
    {
        return (int)xs.size();
    }

    int ny() const
    {
        return (int)ys.size();
    }
};

ll rect_union_area(const vector<Rect> &rects)
{
    Disc2D d;
    for (const Rect &r : rects)
    {
        d.add(r);
    }
    d.build();

    int nx = d.nx(), ny = d.ny();
    if (nx < 2 || ny < 2)
    {
        return 0;
    }

    vector<vector<char>> cover(nx, vector<char>(ny, 0));
    for (const Rect &r : rects)
    {
        int lx = d.ix(min(r.x1, r.x2)), rx = d.ix(max(r.x1, r.x2));
        int ly = d.iy(min(r.y1, r.y2)), ry = d.iy(max(r.y1, r.y2));
        for (int i = lx; i < rx; i++)
        {
            for (int j = ly; j < ry; j++)
            {
                cover[i][j] = 1;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i + 1 < nx; i++)
    {
        for (int j = 0; j + 1 < ny; j++)
        {
            if (cover[i][j])
            {
                ans += (d.xs[i + 1] - d.xs[i]) * (d.ys[j + 1] - d.ys[j]);
            }
        }
    }
    return ans;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<Rect> rects(n);
    for (int i = 0; i < n; i++)
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;

    cout << rect_union_area(rects) << "\n";

    // 若还要在压缩网格上跑差分 / 前缀和，自己用 Disc2D 做：
    // Disc2D d;
    // for (auto &r : rects) d.add(r);
    // d.build();
    // vector<vector<ll>> diff(d.nx() + 1, vector<ll>(d.ny() + 1, 0));
    ==================================================================== */
