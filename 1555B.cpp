#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll W, H;
    cin >> W >> H;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll w, h;
    cin >> w >> h;

    if (w > W || h > H)
    {
        cout << -1 << '\n';
        return;
    }

    vector<vector<int>> grid(W + 1, vector<int>(H + 1));
    for (int i = 1; i <= y1; i++)
    {
        for (int j = 1; j <= x1; j++)
            grid[i][j]++;
    }
    for (int i = 1; i <= y2; i++)
    {
        for (int j = 1; j <= x2; j++)
            grid[i][j]++;
    }

    bool ok = 1;
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            if (grid[i][j] == 2)
            {
                ok = 0;
                break;
            }
        }
    }

    if (ok)
    {
        cout << 0.000000000 << '\n';
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