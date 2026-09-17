#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i - 1];

    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
        int target = pref[l - 1] + m;
        int r = upper_bound(pref.begin() + l, pref.begin() + n + 1, target) - pref.begin() - 1;
        ans = max(ans, r - l + 1);
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