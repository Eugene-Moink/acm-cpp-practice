#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> cnt(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int max_cnt = 0;
    for (int i = 1; i <= k; i++)
    {
        max_cnt = max(max_cnt, cnt[i]);
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (cnt[i] + 1 >= max_cnt)
            ans++;
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