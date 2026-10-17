/* =====================================================
枚举_全排列

【用途】
  两种全排列枚举写法：① next_permutation 原地字典序（无递归、可提前 break）；
  ② DFS 回溯手写（可以边枚举边剪枝，也可以枚举「选哪些数」的组合型问题）。
【输入】
  permutations_next：一个元素序列 a（内部会排序）。
  permutations_dfs：元素个数 n，默认枚举 1..n；path / used 由调用方持有。
【输出】
  每产生一种排列，调用一次 visit(当前序列)。
【复杂度】
  O(n! · n)：n ≤ 10 才可用，n = 11 约 4×10^7 次访问，基本到极限。
【易错提醒】
  1. next_permutation 的首轮必须从升序开始，否则会漏掉字典序更小的排列；
     用 do-while（第一轮先处理当前排列），不要用 while。
  2. next_permutation 返回 false 表示已经是最后一个排列，循环自然结束。
  3. 有重复元素时会自动跳过重复排列；若要「按下标枚举重复排列」则改用 DFS。
  4. DFS 的 used 标记必须在递归返回后复位，漏一次就少了整棵子树。
  5. DFS 递归深度 = n，n > 12 时栈和耗时都不可接受。
===================================================== */
void permutations_next(vector<int> a, const function<void(const vector<int> &)> &visit)
{
    sort(a.begin(), a.end());
    do
    {
        visit(a);
    } while (next_permutation(a.begin(), a.end()));
}

void permutations_dfs(int n, vector<int> &path, vector<char> &used,
                      const function<void(const vector<int> &)> &visit)
{
    if ((int)path.size() == n)
    {
        visit(path);
        return;
    }
    for (int v = 1; v <= n; v++)
    {
        if (used[v])
        {
            continue;
        }
        used[v] = 1;
        path.push_back(v);
        permutations_dfs(n, path, used, visit);
        path.pop_back();
        used[v] = 0;
    }
}

/* ==================== 调用示例（贴进自己的 main） ====================
    // ① 字典序：对数组求全部排列
    vector<int> a = {1, 2, 3};
    permutations_next(a, [](const vector<int> &p)
    {
        for (int x : p)
            cout << x << " ";
        cout << "\n";
    });

    // ② DFS：枚举 1..n 的排列，可在 visit 里剪枝
    int n;
    cin >> n;
    vector<int> path;
    vector<char> used(n + 1, 0);
    permutations_dfs(n, path, used, [](const vector<int> &p)
    {
        for (int x : p)
            cout << x << " ";
        cout << "\n";
    });
   ==================================================================== */
