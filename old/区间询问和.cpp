#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    vector<ll> diff(n + 2, 0); 
    for (ll i = 0; i < q; i++) 
    {
        ll l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    vector<ll> freq(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        freq[i] = freq[i - 1] + diff[i];
    }

    sort(a.begin(), a.end());
    sort(freq.begin() + 1, freq.end()); 

    ll ans = 0;
    for (ll i = 0; i < n; i++) 
    {
        ans += a[i] * freq[i + 1]; 
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}