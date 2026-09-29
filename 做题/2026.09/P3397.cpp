#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> diff2(n + 2, vector<ll>(n + 2, 0));
    while (m--)
    {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        diff2[X1][Y1] += 1;
        diff2[X1][Y2 + 1] -= 1;
        diff2[X2 + 1][Y1] -= 1;
        diff2[X2 + 1][Y2 + 1] += 1;
    }

    vector<vector<ll>> ans2(n + 1, vector<ll>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans2[i][j] = diff2[i][j] + ans2[i - 1][j] + ans2[i][j - 1] - ans2[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans2[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}