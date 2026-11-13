#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<int> ans(n + 1);
    vector<bool> vis(n + 1, false);
    for (int x = 1; x <= n; x++)
    {
        int pos = b[x] + n - x + 1;

        if (pos < 1 || pos > n)
        {
            cout << -1 << '\n';
            return;
        }

        if (vis[pos] == true)
        {
            cout << -1 << '\n';
            return;
        }

        vis[pos] = true;
        ans[pos] = x;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << '\n';
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