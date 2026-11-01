#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;

    int total = x + y + z;
    string ans = "";

    if (y >= z)
    {
        for (int i = 0; i < total; i++)
        {
            ans += 'R';
        }
    }
    else if (z >= x)
    {
        for (int i = 0; i < total; i++)
        {
            ans += 'S';
        }
    }
    else
    {
        for (int i = 0; i < total; i++)
        {
            ans += 'P';
        }
    }

    cout << ans << "\n";
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