#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int calc(vector<int> &times)
{
    int sum = 0;
    for (int t : times)
        sum += t;

    int V = sum / 2;
    vector<int> dp(V + 1, 0);

    for (int t : times)
    {
        for (int j = V; j >= t; j--)
        {
            dp[j] = max(dp[j], dp[j - t] + t);
        }
    }

    return sum - dp[V];
}

void solve()
{
    vector<int> s(4);
    for (int &val : s)
        cin >> val;

    int ans = 0;

    for (int i = 0; i < 4; i++)
    {
        vector<int> times(s[i]);
        for (int j = 0; j < s[i]; j++)
            cin >> times[j];

        ans += calc(times);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}