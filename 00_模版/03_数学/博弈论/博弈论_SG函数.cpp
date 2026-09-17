/*
 * 博弈论 SG 函数（Sprague-Grundy）
 *
 * 用途：公平组合游戏（Nim 类游戏）判断先手胜负
 * 定理：SG 异或和 != 0 → 先手必胜；== 0 → 先手必败
 *
 * 单堆 SG 求法：
 *   sg[x] = mex({ sg[y] : x 能一步到 y })
 *   mex(S) = 最小的不在 S 中的非负整数
 *
 * 复杂度：O(状态数 * 转移数)
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

const int MAXN = 1005;

int sg[MAXN];

void calc_sg(int n, const vector<int> &move)
{
    for (int x = 0; x <= n; x++)
    {
        set<int> reachable;
        for (int mv : move)
        {
            if (x >= mv)
                reachable.insert(sg[x - mv]);
        }

        int g = 0;
        while (reachable.count(g))
            g++;
        sg[x] = g;
    }
}

void solve()
{
    int n, k;
    if (!(cin >> n >> k))
        return;

    vector<int> move(k);
    for (int i = 0; i < k; i++)
        cin >> move[i];

    calc_sg(n, move);

    cout << (sg[n] != 0 ? "Win" : "Lose") << "\n";
}
