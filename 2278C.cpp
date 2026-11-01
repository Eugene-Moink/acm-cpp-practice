#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    bool has_big = false;
    bool has_inner_big = false;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] >= 2)
        {
            has_big = true;
            if (i > 0 && i < n - 1)
            {
                has_inner_big = true;
            }
        }
    }

    if (!has_big)
    {
        cout << -1 << "\n";
    }
    else if (has_inner_big)
    {
        cout << sum - 1 << "\n";
    }
    else
    {
        cout << sum - (n - 1) << "\n";
    }
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