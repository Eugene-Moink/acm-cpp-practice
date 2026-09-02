#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int vis[105][105];

void moink()
{
    int n;
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
            {
                vis[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            if (vis[i][j] == 1)
                ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}