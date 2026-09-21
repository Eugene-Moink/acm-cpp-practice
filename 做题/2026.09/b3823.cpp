#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b, k, r, c;
    cin >> a >> b >> k >> r >> c;

    ll hours = b - a;
    ll ans = hours * k * (r - c);

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}