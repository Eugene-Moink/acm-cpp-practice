#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int max_cnt = 0;
    for (auto &p : cnt)
    {
        max_cnt = max(max_cnt, p.second);
    }

    int ans = INT_MAX;
    if (max_cnt == cnt.size())
    {
        ans = min(max_cnt - 1, (int)cnt.size());
    }
    else
    {
        ans = min(max_cnt, (int)cnt.size());
    }
    cout << ans << '\n';
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