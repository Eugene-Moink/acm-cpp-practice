#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    bool has_small = false;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x < n)
        {
            has_small = true;
        }
    }

    if (has_small)
    {
        cout << n << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}