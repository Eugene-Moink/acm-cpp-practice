#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    map<int, int> cnt;
    for (ll i = 0; i < n;i++)
    {
        cnt[a[i] - 1]++;
        cnt[a[i]]++;
        cnt[a[i] + 1]++;
    }

    ll ans = 0;
    for(auto &p:cnt)
    {
        ans = max(ans, (ll)p.second);
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}