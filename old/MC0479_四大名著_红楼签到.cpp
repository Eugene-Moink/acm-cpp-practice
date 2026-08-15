#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> arr(n + 1);
    for (ll i = 1; i <= n;i++)
    {
        cin >> arr[i];
    }

    while(q--)
    {
        ll opt, i, v;
        cin >> opt >> i >> v;
        if(opt==1)
        {
            arr[i] += v;
        }

        if(opt==2)
        {
            arr[i] -= v;
        }
    }

    for (ll i = 1; i <= n;i++)
    {
        cout << arr[i];
        if(i<n)
        {
            cout << " ";
        }
    }
    return 0;
}