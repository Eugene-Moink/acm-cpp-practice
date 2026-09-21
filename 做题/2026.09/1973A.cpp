#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    if ((a + b + c) % 2 == 0)
    {
        int tmp = min(a + b, (a + b + c) / 2);
        cout << tmp << '\n';
    }
    else
        cout << -1 << '\n';
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