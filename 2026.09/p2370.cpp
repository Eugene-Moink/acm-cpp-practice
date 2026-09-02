#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1005];

void solve()
{
    int n, S;
    ll p;
    cin >> n >> p >> S;

    vector<pair<int, ll>> files;
    for (int i = 0; i < n; i++)
    {
        int w;
        ll v;
        cin >> w >> v;
        files.push_back({w, v});
    }

    sort(files.begin(), files.end());

    for (int i = 0; i < n; i++)
    {
        int w = files[i].first;
        ll v = files[i].second;

        for (int j = S; j >= w; j--)
        {
            dp[j] = max(dp[j], dp[j - w] + v);
        }

        ll max_val = 0;
        for (int j = 0; j <= S; j++)
        {
            max_val = max(max_val, dp[j]);
        }

        if (max_val >= p)
        {
            cout << w << '\n';
            return;
        }
    }

    cout << "No Solution!" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}