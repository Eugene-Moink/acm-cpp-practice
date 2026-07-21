#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    ll ans = 0;
    for (ll i = 0; i < n;i++)
    {
        ll min_num = LLONG_MAX;
        for (ll j = i;j < n;j++)
        {
            min_num = min(min_num, arr[j]);
            ans += min_num;
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}