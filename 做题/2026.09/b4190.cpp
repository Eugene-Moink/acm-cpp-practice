#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    ll k = n + 1;

    if (k == 1)
    {
        cout << 0 << '\n';
        return;
    }

    if (k % 2 == 0)
        cout << k / 2 << '\n';
    else
        cout << k << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}