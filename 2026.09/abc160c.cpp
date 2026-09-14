#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int ans = a[0];
    for (int i = 0; i + 1 < n; i++)
    {
        int cur = a[i + 1] - a[i];
        ans = max(cur, ans);
    }
    ans = max(a[0] + k - a[n - 1], ans);
    cout << k - ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}