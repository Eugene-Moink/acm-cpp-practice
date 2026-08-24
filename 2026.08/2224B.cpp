#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());
    swap(a[0], a[n - 1]);

    sort(a.begin() + 1, a.end());

    vector<ll> uni, dup;
    for (int i = 1; i < n; ++i)
    {
        if (uni.empty() || uni.back() != a[i])
        {
            uni.push_back(a[i]);
        }
        else
        {
            dup.push_back(a[i]);
        }
    }

    vector<ll> b;
    b.push_back(a[0]);
    for (ll x : uni)
        b.push_back(x);
    for (ll x : dup)
        b.push_back(x);

    ll ans = 0, mx = 0, mex = 0;
    map<ll, int> cnt;
    for (ll x : b)
    {
        cnt[x]++;
        mx = max(mx, x);
        while (cnt[mex])
            mex++;
        ans += mx + mex;
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
        moink();
    return 0;
}