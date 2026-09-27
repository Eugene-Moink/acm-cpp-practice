#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, r;
    cin >> n >> r;

    int cx = (n + 1) / 2;
    int cy = (n + 1) / 2;
    int r2 = r * r;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int dx = i - cx;
            int dy = j - cy;
            if (dx * dx + dy * dy <= r2)
                cout << '#';
            else
                cout << '.';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}