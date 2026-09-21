#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    while (n--)
    {
        string s;
        cin >> s;
        for (char c : s)
        {
            if (c == '#')
            {
                ans++;
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