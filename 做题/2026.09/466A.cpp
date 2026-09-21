#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    ll cnt1 = n * a;
    ll cnt2 = (n + m - 1) / m * b;
    ll cnt3 = (n / m) * b + n % m * a;
    ll ans = min({cnt1, cnt2, cnt3});
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}