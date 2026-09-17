#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll k, n;
    cin >> k >> n;

    ll mod = 1;
    for (int i = 0; i < k; i++)
        mod *= 10;
    mod -= 1;

    if (n % mod == 0)
        cout << "aya\n";
    else
        cout << "baka\n";
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