#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 100003;

ll dp[100005];

void moink()
{
    int n, k;
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 0;
        for (int j = 0; j <= k && j <= i; j++)
        {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    cout << dp[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}