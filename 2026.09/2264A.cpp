#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> idx;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            idx.push_back(i);
        }
    }

    int m = idx.size();
    for (int i = 0; i < m; i++)
    {
        if (a[idx[i]] != idx[m - 1 - i] + 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}