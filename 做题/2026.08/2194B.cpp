#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    ll sum = 0;
    for (int num : a)
    {
        sum += (num / x) * y;
    }

    ll max_val = -1;
    for (int cur : a)
    {
        max_val = max(max_val, cur - (cur / x) * y);
    }
    cout << sum + max_val << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}