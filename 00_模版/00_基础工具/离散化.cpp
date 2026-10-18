/* =====================================================
离散化

【用途】
  把大值域压缩成 1..k 的紧凑下标，配合差分、树状数组、并查集使用。
【输入】
  disc_build(v)：v 里放所有需要用到的原始值（先 push_back 再 build）。
【输出】
  disc_id(v, x) 返回 1-based 下标；disc_val(v, i) 返回下标 i 对应的原始值；disc_size(v) 返回点数。
【复杂度】
  disc_build 为 O(k log k)，disc_id / disc_val 为 O(log k)。
【易错提醒】
  1. 必须先 disc_build 再 disc_id，否则 id 会出错。
  2. disc_id 返回 1-based，方便差分和并查集直接使用（0-based 用 disc_id0）。
  3. disc_id(x) 要求 x 一定已经在 v 里，否则会得到错误下标（返回 size+1）。
  4. 多组数据每组重新定义一个 vector 即可，无需手动清空。
  5. 二维离散化（矩形覆盖 / 矩形并面积）见同目录 离散化_二维.cpp。
===================================================== */

// 排序 + 去重（原地压缩）
void disc_build(vector<int> &v)
{
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

// 原始值 x -> 1-based 压缩下标
int disc_id(const vector<int> &v, int x)
{
    return (int)(lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
}

// 原始值 x -> 0-based 压缩下标（树状数组等内部用）
int disc_id0(const vector<int> &v, int x)
{
    return (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
}

// 1-based 压缩下标 -> 原始值
int disc_val(const vector<int> &v, int i)
{
    return v[i - 1];
}

// 压缩后的点数
int disc_size(const vector<int> &v)
{
    return (int)v.size();
}

/* ==================== 调用示例（贴进自己的 main） ====================
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    disc_build(v);                       // 排序去重，v = 压缩后的坐标表
    int p = disc_id(v, v[0]);            // 1-based 下标，给差分 / 并查集 / BIT 用
    int q = disc_id0(v, v[0]);           // 0-based 下标，给数组下标用
    int raw = disc_val(v, p);            // 还原原始值
    ==================================================================== */
