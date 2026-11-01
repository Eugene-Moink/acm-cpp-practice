#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    vector<bool> is_taken(m + 1, false);
    vector<ll> ans(n + 1, 0);
    int taken_count = 0;

    while (true)
    {
        int moved_this_round = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (!is_taken[j] && b[j] <= a[i])
                {
                    is_taken[j] = true;
                    ans[i] += b[j];
                    taken_count++;
                    moved_this_round++;
                    break;
                }
            }
        }

        if (taken_count == m || moved_this_round == 0)
        {
            break;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}