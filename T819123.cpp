#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    ll ans = 0;
    for (int i = x; i <= y; i++)
    {
        ans += 1LL * i / z;
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