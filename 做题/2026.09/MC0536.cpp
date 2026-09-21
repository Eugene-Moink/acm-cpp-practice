#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == -1)
            cnt++;
    }

    int b = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b ^= (x & 1);
    }

    if ((cnt & 1) == 0)
    {
        cout << 1 << '\n';
    }
    else
    {
        if (b == 0)
            cout << 1 << '\n';
        else
            cout << -1 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}