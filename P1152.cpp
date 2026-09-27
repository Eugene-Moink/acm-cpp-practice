#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<bool> vis(n, false);
    for (int i = 1; i < n; i++)
    {
        int d = abs(a[i] - a[i - 1]);
        if (d >= 1 && d <= n - 1)
        {
            vis[d] = true;
        }
    }

    bool ok = true;
    for (int i = 1; i <= n - 1; i++)
    {
        if (!vis[i])
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Jolly" : "Not jolly") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}