#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[200][200];

void moink()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= min(i, k); j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
        }
    }
    cout << dp[n][k] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}