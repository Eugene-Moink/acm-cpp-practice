#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int &x : a)
        cin >> x;

    int ans = max(a[0] - 1, n - a[k - 1]);

    for (int i = 0; i < k - 1; ++i)
        ans = max(ans, (a[i + 1] - a[i]) / 2);

    cout << ans << "\n";
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