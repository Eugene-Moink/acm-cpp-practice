#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll ans = 0, ops = 0;

    for (ll i = 0; i < n;i++)
    {
        ll x = arr[i];
        if (ops + x <= k)
        {
            ans += x * (x + 1) / 2;
            ops += x;
        }

        else
        {
            ll remain = k - ops;
            ans += remain * (x + (x - remain + 1)) / 2;
            cout << ans << endl;
            return;
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}