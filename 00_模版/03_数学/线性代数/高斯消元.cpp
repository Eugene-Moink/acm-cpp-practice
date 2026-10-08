/* =====================================================
高斯消元（解线性方程组）

【用途】
  解 n 元一次线性方程组，并判断是唯一解、无解还是无穷多解。
【输入】
  n（未知数个数），接下来 n 行 n+1 列，为增广矩阵（n 列系数 + 1 列右端常数）。
【输出】
  唯一解时每行输出一个解（保留 2 位小数）；无解或无穷多解时输出 "No Solution"。
【复杂度】
  O(n³)。
【易错提醒】
  1. 判零用 EPS = 1e-9；浮点消元必须选列主元（绝对值最大的行），否则误差会被放大。
  2. 无解与无穷多解都输出 "No Solution"（与洛谷 P3389 一致）。若要区分：主元个数 row < n 即无穷多解；
     存在系数全零而右端非零的行则无解。
  3. 增广矩阵是 n 行 n+1 列，右端常数在第 n 列。
  4. 系数矩阵奇异或接近奇异时答案不可靠，需要精确解时改用取模版高斯消元。
===================================================== */

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

    vector<int> where(n, -1);
    int row = 0;

    for (int col = 0; col < n && row < n; col++)
    {
        int pivot = row;
        for (int i = row; i < n; i++)
        {
            if (fabs(a[i][col]) > fabs(a[pivot][col]))
                pivot = i;
        }

        if (fabs(a[pivot][col]) < EPS)
            continue;

        swap(a[row], a[pivot]);
        double div = a[row][col];
        for (int j = col; j <= n; j++)
            a[row][j] /= div;

        for (int i = 0; i < n; i++)
        {
            if (i == row)
                continue;
            double factor = a[i][col];
            if (fabs(factor) < EPS)
                continue;
            for (int j = col; j <= n; j++)
            {
                a[i][j] -= factor * a[row][j];
            }
        }

        where[col] = row;
        row++;
    }

    for (int i = 0; i < n; i++)
    {
        bool all_zero = true;
        for (int j = 0; j < n; j++)
        {
            if (fabs(a[i][j]) > EPS)
                all_zero = false;
        }
        if (all_zero && fabs(a[i][n]) > EPS)
        {
            cout << "No Solution\n";
            return;
        }
    }

    if (row < n)
    {
        cout << "No Solution\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(2) << a[where[i]][n] << "\n";
    }
}
