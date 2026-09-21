#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countDivisible(ll x, ll c, ll d)
{
    if (x <= 0)
        return 0;
    ll l = c / __gcd(c, d) * d;
    return x / c + x / d - x / l;
}

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll total = b - a + 1;
    ll divisible = countDivisible(b, c, d) - countDivisible(a - 1, c, d);
    cout << total - divisible << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}