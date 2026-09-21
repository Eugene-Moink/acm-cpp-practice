#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x, y;
    cin >> x >> y;

    ll d = abs(x - y);
    if (d % 6 == 0 || d % 6 == 1 || d % 6 == 5)
        cout << "Bob\n";
    else
        cout << "Alice\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}