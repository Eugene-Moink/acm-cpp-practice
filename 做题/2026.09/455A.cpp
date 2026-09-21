#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[100005];
void solve()
{
    int n;
    cin >> n;
    int max_val = 0;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
        max_val = max(max_val, x);
    }

    vector<int> cnt(100005, 0);
    for (int x : a)
    {
        cnt[x]++;
    }

    dp[1] = cnt[1];
    for (int i = 2; i <= 100000; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * i * cnt[i]);
    }

    cout << dp[max_val] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}