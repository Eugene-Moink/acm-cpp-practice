/* =====================================================
离散化_二维

【用途】
  把 n 个矩形的 4 条边界坐标分别压缩成 1..nx / 1..ny 的紧凑下标，
  在「压缩格」上做覆盖标记，解决矩形并面积、矩形并周长、扫描线前处理等问题。
【输入】
  rects：每个矩形写成 array<ll,4>{x1, y1, x2, y2}，两条对角顺序任意，
         内部会 min/max 交换成左下右上；坐标可以为负、可以重复。
【输出】
  rect_union_area(rects) 直接返回矩形并面积（ll）。
  需要复用压缩坐标时用 rect_union_area(rects, xs, ys)，或先 disc2d_build_from_rects 再自己标记。
  压缩下标为 0-based：disc2d_ix(xs, x) / disc2d_iy(ys, y)。
【复杂度】
  离散化 O(n log n)，标记 O(n · nx · ny) 最坏，面积求和 O(nx · ny)。
【易错提醒】
  1. 压缩网格是「格」不是「点」：第 i 行覆盖 [xs[i], xs[i+1])，所以下标只用到 nx-2 / ny-2。
  2. 标记矩形用半开区间 [ix(x1), ix(x2)) × [iy(y1), iy(y2))，右端点不要再 +1。
  3. 面积 = (xs[i+1]-xs[i]) * (ys[j+1]-ys[j])，必须用压缩后的相邻坐标差。
  4. 坐标可以为负、可以重复；重复坐标去重后只留一个，不会影响面积。
  5. 只关心相对大小、不关心真实跨度时也可以用这个套路做矩形并周长。
===================================================== */

// 把一个矩形的 4 条边界坐标加入坐标池（顺序任意）
void disc2d_add(vector<ll> &xs, vector<ll> &ys, ll x1, ll y1, ll x2, ll y2)
{
    xs.push_back(min(x1, x2));
    xs.push_back(max(x1, x2));
    ys.push_back(min(y1, y2));
    ys.push_back(max(y1, y2));
}

// 两维坐标分别排序去重
void disc2d_build(vector<ll> &xs, vector<ll> &ys)
{
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
}

// 从矩形表一次性建好两维坐标（等价于逐个 disc2d_add 再 disc2d_build）
void disc2d_build_from_rects(const vector<array<ll, 4>> &rects, vector<ll> &xs, vector<ll> &ys)
{
    xs.clear();
    ys.clear();
    for (const auto &r : rects)
    {
        disc2d_add(xs, ys, r[0], r[1], r[2], r[3]);
    }
    disc2d_build(xs, ys);
}

// 原始 x 坐标 -> 0-based 压缩下标
int disc2d_ix(const vector<ll> &xs, ll x)
{
    return (int)(lower_bound(xs.begin(), xs.end(), x) - xs.begin());
}

// 原始 y 坐标 -> 0-based 压缩下标
int disc2d_iy(const vector<ll> &ys, ll y)
{
    return (int)(lower_bound(ys.begin(), ys.end(), y) - ys.begin());
}

// 矩形并面积；顺带把压缩后的坐标表带出来（xs / ys），方便再跑差分 / 前缀和
ll rect_union_area(const vector<array<ll, 4>> &rects, vector<ll> &xs, vector<ll> &ys)
{
    disc2d_build_from_rects(rects, xs, ys);

    int nx = (int)xs.size(), ny = (int)ys.size();
    if (nx < 2 || ny < 2)
    {
        return 0;
    }

    vector<vector<char>> cover(nx, vector<char>(ny, 0));
    for (const auto &r : rects)
    {
        int lx = disc2d_ix(xs, min(r[0], r[2])), rx = disc2d_ix(xs, max(r[0], r[2]));
        int ly = disc2d_iy(ys, min(r[1], r[3])), ry = disc2d_iy(ys, max(r[1], r[3]));
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
                ans += (xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]);
            }
        }
    }
    return ans;
}

// 只要面积的简版（内部自建坐标表）
ll rect_union_area(const vector<array<ll, 4>> &rects)
{
    vector<ll> xs, ys;
    return rect_union_area(rects, xs, ys);
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<array<ll, 4>> rects(n);
    for (int i = 0; i < n; i++)
        cin >> rects[i][0] >> rects[i][1] >> rects[i][2] >> rects[i][3];

    cout << rect_union_area(rects) << "\n";

    // 若还要在压缩网格上跑差分 / 前缀和，自己拿坐标表：
    // vector<ll> xs, ys;
    // ll area = rect_union_area(rects, xs, ys);
    // vector<vector<ll>> diff(xs.size() + 1, vector<ll>(ys.size() + 1, 0));
    ==================================================================== */
