#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[10005];

void solve()
{
    int v, n, c;
    cin >> v >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int k, m;
        cin >> k >> m;

        for (int j = c; j >= m; j--)
        {
            dp[j] = max(dp[j], dp[j - m] + k);
        }
    }

    for (int j = 0; j <= c; j++)
    {
        if (dp[j] >= v)
        {
            cout << c - j << '\n';
            return;
        }
    }

    cout << "Impossible" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}