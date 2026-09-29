#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << max(abs(a - b), abs(a + c - b)) << '\n';
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