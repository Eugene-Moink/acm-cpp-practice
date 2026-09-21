#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll h, w;
    cin >> h >> w;

    if (h == 1 || w == 1)
        cout << 1;
    else
        cout << (h * w + 1) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}