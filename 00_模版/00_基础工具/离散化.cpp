/* =====================================================
离散化

【用途】
  把大值域压缩成 1..k 的紧凑下标，配合差分、树状数组、并查集使用。
【输入】
  add(x) 逐个加入所有需要用到的原始值。
【输出】
  id(x) 返回 1-based 下标；val(i) 返回下标对应的原始值；size() 返回点数。
【复杂度】
  build() 为 O(k log k)，id / val 为 O(log k)。
【易错提醒】
  1. 必须先 add 再 build，否则 id 会出错。
  2. id 返回 1-based，方便差分和并查集直接使用。
  3. id(x) 要求 x 一定已经 add 过，否则会得到错误下标。
  4. 多组数据每组重新定义一个对象即可，无需手动清空。
  5. 二维离散化（矩形覆盖 / 矩形并面积）见同目录 离散化_二维.cpp。
===================================================== */
struct Disc
{
    vector<int> vals;

    void add(int x)
    {
        vals.push_back(x);
    }

    void build()
    {
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
    }

    int id(int x) const
    {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
    }

    int val(int i) const
    {
        return vals[i - 1];
    }

    int size() const
    {
        return vals.size();
    }
};