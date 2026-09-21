/*
 * 矩阵快速幂
 *
 * 用途：求线性递推式第 N 项（如斐波那契、递推式求解）
 * 复杂度：O(k^3 log N)，k 为矩阵大小
 *
 * 输入：n（递推阶数）、N（求第 N 项）
 * 输出：结果矩阵或结果数
 *
 * 多组数据：取消 main 中 // cin >> T; 的注释
 */

const ll MOD = 998244353;
const int MAXK = 105;

struct Matrix
{
    int n, m;
    ll a[MAXK][MAXK];

    Matrix(int n = 0, int m = 0) : n(n), m(m)
    {
        memset(a, 0, sizeof(a));
    }

    Matrix operator*(const Matrix &other) const
    {
        Matrix res(n, other.m);
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < m; k++)
            {
                if (a[i][k] == 0)
                    continue;
                for (int j = 0; j < other.m; j++)
                {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix mat_pow(Matrix base, ll exp)
{
    int n = base.n;
    Matrix res(n, n);
    for (int i = 0; i < n; i++)
        res.a[i][i] = 1;

    while (exp > 0)
    {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}