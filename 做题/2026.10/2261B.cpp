#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    int mx = INT_MIN, mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    if (mx == mn)
    {
        cout << mx << '\n';
    }

    else
    {
        int x = mn ^ mx;
        int mask = 1;
        while (mask <= x)
        {
            mask <<= 1;
        }
        cout << (mx | (mask - 1)) << '\n';
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