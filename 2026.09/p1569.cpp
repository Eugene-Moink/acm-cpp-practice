#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[1005];

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    fill(dp, dp + n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (dp[j] != -1 && pref[i] >= pref[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    if (dp[n] == -1)
        cout << "Impossible" << '\n';
    else
        cout << dp[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}