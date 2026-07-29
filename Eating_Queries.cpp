#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<ll> pre(n + 1);

    for (int i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<ll>());

    for (int i = 1; i <= n;i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    while (q--)
    {
        ll x;
        cin >> x;
        auto it = lower_bound(pre.begin() + 1, pre.end(), x);
        if(it==pre.end())
        {
            cout << "-1" << endl;
        }
        else
            cout << (it - pre.begin()) << endl;
    }
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