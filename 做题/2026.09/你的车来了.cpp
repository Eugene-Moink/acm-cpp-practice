/*
TASK: ride
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll get_mod(const string &s)
{
    ll res = 1;
    for (char c : s)
    {
        res *= (c - 'A' + 1);
        res %= 47;
    }
    return res;
}

void solve()
{
    string comet, group;
    cin >> comet >> group;
    if (get_mod(comet) == get_mod(group))
        cout << "GO" << '\n';
    else
        cout << "STAY" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    solve();
    return 0;
}