#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> st(n + 1);
    vector<pair<ll, ll>> point(m + 1);
    for (ll i = 1; i <= n;i++)
    {
        cin >> st[i].first >> st[i].second;
    }
    for (ll i = 1; i <= m;i++)
    {
        cin >> point[i].first >> point[i].second;
    }

    for (ll i = 1; i <= n;i++)
    {
        ll best = 1;
        ll min_dist = abs(st[i].first - point[1].first) + abs(st[i].second - point[1].second);
        for (ll j = 2; j <= m;j++)
        {
            ll dist = abs(st[i].first - point[j].first) + abs(st[i].second - point[j].second);
            if (dist < min_dist) 
            {   
                min_dist = dist;
                best = j;
            }
        }
        cout << best << endl;
    }
}

int main()
{
    moink();
    return 0;
}