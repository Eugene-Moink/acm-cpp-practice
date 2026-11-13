#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (z >= x || z >= y)
        cout << 1;
    else
        cout << 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}