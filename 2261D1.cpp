#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    int k = (n + 1) / 2;
    cout << k << '\n';

    for (int i = 1; i <= k; i++)
    {
        int l = i + 1;
        int r = min(n, i + k);
        cout << l << ' ' << r << '\n';
    }
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