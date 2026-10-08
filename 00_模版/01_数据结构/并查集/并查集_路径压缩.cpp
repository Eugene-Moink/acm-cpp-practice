/* =====================================================
并查集（路径压缩）

【用途】
  维护不相交集合：合并两个集合、判断两个元素是否属于同一集合、求连通块个数。
【输入】
  init(n)：元素编号 1..n。
【输出】
  find(x) 返回所在集合的代表元；merge / isSame 直接生效。
【复杂度】
  仅路径压缩时单次近似 O(log n)，最坏可退化；配合按秩合并才是 O(α(n))。
【易错提醒】
  1. 必须先 init(n) 再使用；多组数据要重新 init。
  2. 元素编号从 1 开始，fa 开 n + 1。
  3. 递归版 find 在链很长时可能爆栈，必要时改成 while 循环版。
  4. 只调用 find 不会合并，合并一定要走 merge。
===================================================== */
struct DSU
{
    vector<int> fa;

    DSU(int n = 0) { init(n); }

    void init(int n)
    {
        fa.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
    }

    int find(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
            fa[fx] = fy;
    }

    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }
};