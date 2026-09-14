#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    int cur = 0;
    while (n--)
    {
        int tmp = 0;
        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            tmp += x;
        }
        if (tmp < cur)
            cnt++;

        cur = tmp;
    }
    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}