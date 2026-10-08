#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b;
    cin >> a >> b;

    ll total = a * 60 + b;
    ll h = (total / 60) % 24;
    ll m = total % 60;

    cout << h << ' ' << m << '\n';
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