#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n;i++)
    {
        int left = lower_bound(a.begin() + 1 + i, a.end(), l - a[i]) - a.begin();
        int right = upper_bound(a.begin() + 1 + i, a.end(), r - a[i]) - a.begin();
        if(right > left)
            ans += right - left;
    }
    cout << ans << '\n';
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