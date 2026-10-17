#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    if (y % x != 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    int m = y / x;
    int ans = 0;

    for (int i = 1; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            int j = m / i;
            if (__gcd(i, j) == 1)
            {
                if (i == j)
                    ans += 1;
                else
                    ans += 2;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}