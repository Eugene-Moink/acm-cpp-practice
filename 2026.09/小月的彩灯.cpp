#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int x;
    ll k;
    cin >> x >> k;
    k = k % 4;
    while (k--)
    {
        x = ((x << 1) | (x >> 3)) & 15;
    }
    int c = __builtin_popcount(x);
    cout << x << ' ' << c << '\n';
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