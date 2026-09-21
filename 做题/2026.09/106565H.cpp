#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    int T_acm = (n + 2) / 3;
    int acm = 0;
    for (int x = T_acm; x >= 0; x--)
    {

        int girls_in_girl_teams = min(m, 3 * x);
        if (n - girls_in_girl_teams <= 3 * (T_acm - x))
        {
            acm = x;
            break;
        }
    }

    int T_tt = (n + 9) / 10;
    int tt = 0;
    for (int x = T_tt; x >= 0; x--)
    {
        if (6 * x <= m)
        {
            tt = x;
            break;
        }
    }

    cout << acm << ' ' << tt << '\n';
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