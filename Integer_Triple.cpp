#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin >> n;
    if (n % 2 != 0)
    {
        cout << -1 << '\n';
        return;
    }

    cout << 1 << ' ' << n / 2 << ' ' << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}