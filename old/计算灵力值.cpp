#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin>>n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n;i++)
    {
        cin >> a[i];
    }

    priority_queue<ll> pq;
    ll ans = 0;
    for (ll i = n; i >= 1;--i)
    {
        if(a[i]>0)
        {
            if (i % 2 == 0)
                ans += a[i];
            else
                pq.push(a[i]);
        }
        else if (a[i] < 0)
        {
            if(!pq.empty())
            {
                ans += pq.top();
                pq.pop();
            }
        }
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