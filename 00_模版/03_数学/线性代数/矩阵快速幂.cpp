/* =====================================================
矩阵快速幂

【用途】
  求线性递推式的第 N 项（斐波那契、各种递推求和）。
【输入】
  矩阵阶数 k 与指数 N；先把递推矩阵填好。
【输出】
  结果矩阵，通常取 res.a[i][j] 作为答案。
【复杂度】
  O(k³ log N)。
【易错提醒】
  1. 矩阵是定长 MAXK × MAXK，k 不能超过 MAXK。
  2. 单位矩阵要对角线置 1，否则不是快速幂。
  3. 乘法的三重循环把 k 放中间，可以跳过 a[i][k] == 0 的情况，快很多。
  4. 本文件 MOD 是 ll 版，与 组合数学/组合数预处理.cpp 的 int MOD 同名，一次只贴一个。
  5. 多组数据：在 main 里取消 // cin >> T; 的注释。
===================================================== */

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