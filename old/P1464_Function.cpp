#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[25][25][25];

ll w(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (dp[a][b][c] != -1)
        return dp[a][b][c];

    if (a < b && b < c)
        dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

    else
        dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

    return dp[a][b][c];
}

void moink()
{
    memset(dp, -1, sizeof(dp));

    ll a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a == -1 && b == -1 && c == -1)
            break;

        ll ans = w(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}