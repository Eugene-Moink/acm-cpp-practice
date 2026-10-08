#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{

    int x, y;
    cin >> x >> y;
    int z = gcd(x, y);
    int a = x, b = y, c = z;
    int mx = max({a, b, c});
    int sum = a + b + c;
    if (mx < sum - mx)
        cout << "Yes\n";
    else
        cout << "No\n";
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