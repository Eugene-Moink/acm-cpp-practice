/*
 * 离散化模板
 *
 * 用法：
 *   1. 先调用 add(x) 把所有需要用到的原始值加入
 *   2. 调用 build() 排序去重
 *   3. 用 id(x) 查原始值 x 离散化后的下标（1-based）
 *   4. 用 val(i) 查下标 i 对应的原始值（1-based）
 *   5. 用 size() 获取离散化后的总点数
 *
 * 注意：
 *   - 必须先 add 再 build，否则 id 会出错
 *   - id 返回 1-based，方便差分和并查集使用
 *   - 多组数据每组重新定义一个对象即可，无需手动清空
 */
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