#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll s[5005][5005];

void moink()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll x;
            cin >> x;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }
    }

    ll min_cost = 4e18;
    int best_k = 1;

    for (int k = 1; k <= n; k++)
    {
        int blocks = (n + k - 1) / k;
        ll cost = 0;

        for (int i = 1; i <= blocks; i++)
        {
            for (int j = 1; j <= blocks; j++)
            {
                int x1 = (i - 1) * k + 1;
                int y1 = (j - 1) * k + 1;
                int x2 = min(i * k, n);
                int y2 = min(j * k, n);

                ll block_sum = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];

                if (block_sum != 0)
                {
                    cost += 1LL * k * k + 1;
                }
            }
        }

        if (cost < min_cost)
        {
            min_cost = cost;
            best_k = k;
        }
    }

    cout << best_k << " " << min_cost << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}