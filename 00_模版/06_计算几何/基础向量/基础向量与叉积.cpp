/*
 * 基础向量与叉积（方向判定 / 线段相交 / 多边形面积）
 *
 * 【用途】平面整点向量基础运算（加减、点积、叉积）、用叉积判三点方向（左转 / 右转 / 共线）、
 *         线段相交判定（跨立实验 + 共线特判）、多边形面积（鞋带公式）。
 * 【输入】Point{ll x, ll y}；线段由四个端点 a、b、c、d 给出；多边形给顶点序列 poly。
 * 【输出】dot / cross：ll；orientation：1 表示左转（逆时针一侧）、-1 表示右转、0 表示共线；
 *         segment_intersect：bool；polygon_area2：2 倍有向面积（ll，顺时针为负）；
 *         polygon_area：无向面积（double）。
 * 【复杂度】单次判定 O(1)；n 边形面积 O(n)。
 * 【易错提醒】1. 本模板约定 cross(a, b) = a.x * b.y - a.y * b.x，所以 cross(o, a, b) > 0 表示
 *                o->a->b 是左转（逆时针）；叉积符号写反会让所有方向判断整体反掉；
 *             2. 三点共线时 cross == 0，既不是左转也不是右转，跨立实验必须配合 on_segment
 *                单独处理「共线且落在对方线段内」这一种相交；
 *             3. 叉积、点积都用 ll：坐标到 1e9 时单次叉积就到 1e18 量级，多边形求和前先确认不溢出；
 *             4. 鞋带公式得到的是有向面积（逆时针为正、顺时针为负），所以要先取绝对值再除以 2；
 *                多边形顶点必须按顺 / 逆时针依次给出，乱序会得到错误面积；
 *             5. 比较面积大小时用 2 倍面积的 ll 值（polygon_area2 的绝对值）精确比较，别用 double。
 */

/* ==================== 一、向量基础 ==================== */

struct Point
{
    ll x, y;

    Point operator+(const Point &o) const
    {
        return {x + o.x, y + o.y};
    }

    Point operator-(const Point &o) const
    {
        return {x - o.x, y - o.y};
    }

    Point operator*(ll k) const
    {
        return {x * k, y * k};
    }

    bool operator==(const Point &o) const
    {
        return x == o.x && y == o.y;
    }
};

ll dot(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}

ll cross(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

ll cross(const Point &o, const Point &a, const Point &b)
{
    return cross(a - o, b - o);
}

ll dist2(const Point &a, const Point &b)
{
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

/* ==================== 二、判方向（cross(o, a, b) 的符号） ==================== */

int orientation(const Point &o, const Point &a, const Point &b)
{
    ll s = cross(o, a, b);

    if (s > 0)
        return 1;

    if (s < 0)
        return -1;

    return 0;
}

/* ==================== 三、线段相交判定（跨立实验 + 共线特判） ==================== */

bool on_segment(const Point &a, const Point &b, const Point &p)
{
    if (cross(a, b, p) != 0)
        return false;

    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

bool segment_intersect(const Point &a, const Point &b, const Point &c, const Point &d)
{
    ll d1 = cross(a, b, c);
    ll d2 = cross(a, b, d);
    ll d3 = cross(c, d, a);
    ll d4 = cross(c, d, b);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;

    if (d1 == 0 && on_segment(a, b, c))
        return true;

    if (d2 == 0 && on_segment(a, b, d))
        return true;

    if (d3 == 0 && on_segment(c, d, a))
        return true;

    if (d4 == 0 && on_segment(c, d, b))
        return true;

    return false;
}

/* ==================== 四、多边形面积（鞋带公式） ==================== */

ll polygon_area2(const vector<Point> &poly)
{
    int n = (int)poly.size();
    ll s = 0;

    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        s += poly[i].x * poly[j].y - poly[j].x * poly[i].y;
    }

    return s;
}

double polygon_area(const vector<Point> &poly)
{
    return fabs((double)polygon_area2(poly)) / 2.0;
}

/* ==================== 调用示例（贴进自己的 main） ====================
    Point a{0, 0}, b{4, 0}, c{0, 3};

    cout << dot(b - a, c - a) << "\n";                // 点积
    cout << cross(a, b, c) << "\n";                   // > 0 左转，< 0 右转，0 共线
    cout << orientation(a, b, c) << "\n";             // 1 / -1 / 0
    cout << dist2(a, b) << "\n";                      // 两点距离的平方

    Point d{2, -1}, e{2, 4};
    cout << (segment_intersect(a, b, d, e) ? "相交" : "不相交") << "\n";
    cout << (on_segment(a, b, Point{2, 0}) ? "在线段上" : "不在线段上") << "\n";

    vector<Point> poly = {{0, 0}, {4, 0}, {4, 3}, {0, 3}};
    cout << polygon_area2(poly) << "\n";              // 24（顺时针给出则为 -24）
    cout << polygon_area(poly) << "\n";               // 12
==================================================================== */
