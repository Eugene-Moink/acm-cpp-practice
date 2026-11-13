#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    if (x > y)
    {
        cout << 0 << '\n';
        return;
    }
    else
        cout << y - x + 1 << '\n';
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