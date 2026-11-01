#include <bits/stdc++.h>
using namespace std;

vector<int> get_f(vector<int> &a)
{
    int n = a.size(), mex = 0;
    vector<int> f(n), vis(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        vis[a[i]] = 1;
        while (vis[mex])
            mex++;
        f[i] = mex;
    }
    return f;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int ans = get_f(a)[n - k];
    int bi = -1, bj = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(a[i], a[j]);
            int cur = get_f(a)[n - k];
            if (cur > ans)
            {
                ans = cur;
                bi = i, bj = j;
            }
            swap(a[i], a[j]);
        }
    }

    if (bi == -1)
        cout << -1 << '\n';
    else
        cout << bi + 1 << ' ' << bj + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}