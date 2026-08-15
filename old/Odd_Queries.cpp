#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n;i++)
    {
        ll x;
        cin >> x;
        pre[i] = (pre[i - 1] + x) % 2;
    }

    while(q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        ll total = pre[n];

        ll old_range = (pre[r] - pre[l - 1] + 2) % 2;

        ll len = r - l + 1;
        ll new_range = (k % 2) * (len % 2) % 2;
        ll result = (total - old_range + new_range + 2) % 2;
        
        if(result==1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}