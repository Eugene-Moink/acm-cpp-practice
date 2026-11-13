#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0, max_val = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        max_val = max(max_val, a[i]);
    }
    if (max_val <= sum / 5 && sum % 5 == 0)
        cout << "T\n";
    else
        cout << "F\n";
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