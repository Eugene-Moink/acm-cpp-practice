#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> point(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> point[i].first >> point[i].second;
    }
    
    while(m--)
    {
        ll x, y, r;
        cin >> x >> y >> r;
        ll cnt = 0;
        for (ll i = 0; i < n;i++)
        {
            ll dx = point[i].first - x;
            ll dy = point[i].second - y;

            if (dx *dx + dy *dy <= r *r)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}

int main()
{
    moink();
    return 0;
}