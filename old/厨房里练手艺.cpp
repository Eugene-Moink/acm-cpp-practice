#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n+1);
    for (ll i = 1; i <= n;i++)
    {
        cin >> arr[i];
    }

    while(q--)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            for (ll i = l; i <= r;i++)
            {
                arr[i] += x;
            }
        }

        if (op == 2)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            for (ll i = l; i <= r;i++)
            {
                if (arr[i] > x)
                {
                    arr[i] = x;
                }
            }
        }

        if (op == 3)
        {
            ll l, r;
            cin >> l >> r;
            ll ans = 0;
            for (ll i = l; i <= r;i++)
            {
                ans += arr[i];
            }
            cout << ans << endl;
        }
    }
}

int main()
{
    moink();
    return 0;
}