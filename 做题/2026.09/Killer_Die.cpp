#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> old(n);
    for (ll &val : old)
        cin >> val;

    sort(old.begin(), old.end());

    vector<ll> cost(n + 1);
    cost[0] = 1;
    for (int w = 1; w <= n; w++)
    {
        cost[w] = old[w - 1] + 1;
    }

    ll ans = LLONG_MAX;

    for (int w = 0; w <= n; w++)
    {
        if (2LL * w > n)
        {
            ans = min(ans, m * cost[w]);
        }
    }

    for (int w1 = 0; w1 <= n; w1++)
    {
        for (int w2 = 0; w2 < w1; w2++)
        {
            for (int w3 = 0; w3 < w2; w3++)
            {
                ll T = n * m / 2 + 1;
                ll c1 = cost[w1], c2 = cost[w2], c3 = cost[w3];
                ll baseWins = m * w3;
                if (baseWins >= T)
                {
                    ans = min(ans, m * c3);
                    continue;
                }
                ll delta = T - baseWins;
                ll dw1 = w1 - w3, dc1 = c1 - c3;
                ll dw2 = w2 - w3, dc2 = c2 - c3;

                ll max_x = min(m, 200LL);
                for (ll x = 0; x <= max_x; x++)
                {
                    ll rem = delta - x * dw1;
                    ll y = 0;
                    if (rem > 0)
                    {
                        y = (rem + dw2 - 1) / dw2;
                    }
                    if (x + y <= m)
                    {
                        ll totalCost = m * c3 + x * dc1 + y * dc2;
                        ans = min(ans, totalCost);
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}