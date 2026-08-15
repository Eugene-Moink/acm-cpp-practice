#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

struct Point 
{
    ll x, y;
};

void moink()
{
    ll n, m;
    cin >> n >> m;
    vector<Point> points(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    vector<ll> ans(n, 0); 

    while (m--)
    {
        ll x, y, r;
        cin >> x >> y >> r;
        
        ll rr = r * r; 

        for (ll i = 0; i < n; i++)
        {
            ll dx = points[i].x - x;
            ll dy = points[i].y - y;

            if (dx * dx + dy * dy <= rr)
            {
                ans[i]++; 
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}