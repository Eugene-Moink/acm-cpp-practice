#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 505;

int r, c, a, b;
ll t[MAXN][MAXN];
ll s[MAXN][MAXN];

bool check(ll x)
{
    int last = 0;
    int line = 0;

    for (int i = 1; i <= r; i++)
    {
        int cnt_v = 0;
        int ups = 0;

        for (int j = 1; j <= c; j++)
        {
            if (s[i][j] - s[last][j] - s[i][ups] + s[last][ups] >= x)
            {
                cnt_v++;
                ups = j;
            }
        }

        if (cnt_v >= b)
        {
            line++;
            last = i;
        }
    }

    return line >= a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> a >> b;

    ll total = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> t[i][j];
            total += t[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + t[i][j];
        }
    }

    ll lo = 0, hi = total, ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}