#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x;
    cin >> x;
    if (x == 0)
    {
        cout << "0 -1 -1" << '\n';
        return;
    }

    ll one = __builtin_popcountll(x);
    ll min_one = __builtin_ctzll(x);
    ll max_one = 63 - __builtin_clzll(x);

    cout << one << " " << min_one << " " << max_one;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}