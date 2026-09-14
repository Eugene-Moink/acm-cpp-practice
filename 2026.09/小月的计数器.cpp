#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    while (n > 0)
    {
        ans += n;
        n >>= 1;
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