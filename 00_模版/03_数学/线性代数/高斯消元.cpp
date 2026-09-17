/*
 * 高斯消元（解线性方程组）
 *
 * 输入：n（未知数个数），接下来 n 行 n+1 列（增广矩阵）
 * 输出：方程组的解，或提示无解/无穷多解
 * 复杂度：O(n^3)
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

const double EPS = 1e-9;

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<vector<double>> a(n, vector<double>(n + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            cin >> a[i][j];

    for (int col = 0; col < n; col++)
    {
        int pivot = col;
        for (int i = col + 1; i < n; i++)
        {
            if (fabs(a[i][col]) > fabs(a[pivot][col]))
                pivot = i;
        }

        if (fabs(a[pivot][col]) < EPS)
        {
            cout << "No Solution\n";
            return;
        }

        swap(a[col], a[pivot]);
        化 double div = a[col][col];
        for (int j = col; j <= n; j++)
            a[col][j] /= div;

        for (int i = 0; i < n; i++)
        {
            if (i == col)
                continue;
            double factor = a[i][col];
            if (fabs(factor) < EPS)
                continue;
            for (int j = col; j <= n; j++)
            {
                a[i][j] -= factor * a[col][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << a[i][n] << "\n";
    }
}