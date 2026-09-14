#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c;
    cin >> n >> c;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int ans = 0;
    for (auto &p : cnt)
    {
        ans += min(p.second, c);
    }
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}