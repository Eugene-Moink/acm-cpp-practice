#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k < n || k > 2 * n - 1)
    {
        cout << -1 << '\n';
        return;
    }
    int c = 2 * n - k;
    vector<vector<int>> A(n, vector<int>(n, 0));

    for (int i = 0; i < c; ++i)
    {
        A[i][i] = i + 1;
    }
    for (int i = c; i < n; ++i)
    {
        A[i][0] = i + 1;
    }
    for (int j = c; j < n; ++j)
    {
        A[0][j] = n + j + 1 - c;
    }

    int nxt = 2 * n - c + 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (A[i][j] == 0)
            {
                A[i][j] = nxt++;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << A[i][j] << (j + 1 == n ? '\n' : ' ');
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}