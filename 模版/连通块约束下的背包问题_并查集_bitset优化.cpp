#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* =====================================================
并查集 + Bitset优化背包模板（全局函数版）

【用途】
  解决带有“分组/捆绑约束”的 0/1 背包（子集和）问题。
  例如：实力相当的人必须一起选，求最接近目标 m 的人数。
  核心逻辑：先用并查集合并所有绑定关系，提取连通块的大小（作为物品重量），再用 Bitset 做 01 背包求可达状态，最后双向查找最接近目标的解。

【参数】
  n (int): 物品总个数（节点总数）。
  m (int): 目标值。
  k (int): 约束关系组数（直接合并次数）。

【全局变量】
  fa (int[MAXN]): 父节点数组，fa[i] 表示 i 的父节点。

【函数说明】
  init(n):   初始化并查集，每个节点独立成一个集合。
  find(x):   查找 x 所在集合的根节点（迭代版，防爆栈）。
  merge(x,y): 合并 x 和 y 所在的集合。

【复杂度】
  时间复杂度 O(N * α(N) + N / 64)，空间复杂度 O(N)。

【易错提醒】
  1. 下标必须从 1 开始，数组开 n + 1 大小。
  2. find 务必使用迭代版（while 循环），防止在数据量极大（>1e4）时递归爆栈（RE）。
  3. Bitset 转移必须用 `dp |= (dp << x)`，代表选（左移）或不选（原状态）的并集。
  4. 每次测试前必须 `dp.reset()`，并设置 `dp[0] = 1`。
  5. 寻找最接近 m 的解时，优先向下找，再向上找，若距离相等则选较小的解。
===================================================== */
const int MAXN = 200005;
int fa[MAXN];

void init(int n)
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}

// 迭代版 find，防止数据过大时递归爆栈
int find(int x)
{
    while (fa[x] != x)
    {
        fa[x] = fa[fa[x]]; // 路径减半
        x = fa[x];
    }
    return x;
}

void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        fa[fx] = fy;
}

/* ==================== 调用示例（原题逻辑） ==================== */
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    // 1. 处理合并关系
    init(n);
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }

    // 2. 提取连通块大小（转化为背包物品）
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cnt[find(i)]++;

    vector<int> blocks;
    for (int i = 1; i <= n; ++i)
        if (cnt[i] != 0)
            blocks.push_back(cnt[i]);

    // 3. Bitset 优化 01 背包（子集和问题）
    bitset<20005> dp; // 数组大小需根据最大 n 调整
    dp.reset();
    dp[0] = 1;
    for (int x : blocks)
        dp |= (dp << x);

    // 4. 双向夹逼找最接近 m 的答案
    int low = -1, high = -1;
    for (int i = m; i >= 0; --i)
        if (dp[i])
        {
            low = i;
            break;
        }
    for (int i = m; i <= n; ++i)
        if (dp[i])
        {
            high = i;
            break;
        }

    if (low == -1)
        cout << high << '\n';
    else if (high == -1)
        cout << low << '\n';
    else
    {
        if (abs(m - low) <= abs(high - m))
            cout << low << '\n';
        else
            cout << high << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}