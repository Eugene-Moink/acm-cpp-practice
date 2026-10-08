#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x0, y0, R;
    cin >> x0 >> y0 >> R;
    int R2 = R * R;
    for (int x = x0 - R; x <= x0 + R; x++)
    {
        for (int y = y0 - R; y <= y0 + R; y++)
        {
            int dx = x - x0;
            int dy = y - y0;
            if (dx * dx + dy * dy == R2)
            {
                cout << x << " " << y << "\n";
                return;
            }
        }
    }
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