#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    ll total = 0;
    for (ll x : cnt)
    {
        if(x>=2)
            total += x * (x - 1) / 2;
    }

    for(ll x : a)
    {
        ll ans = total - (cnt[x] - 1);
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}