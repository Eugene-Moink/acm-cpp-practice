#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    ll ans = 0;
    ll l = 0, r = n - 1;

    while (l < r && arr[l] < c)   
    {
        ans += arr[r] - c;      
        l++;                      
        r--;                    
    }
    for (ll i = l; i <= r; i++)
    {
        ans += arr[i] - c;      
    }

    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}