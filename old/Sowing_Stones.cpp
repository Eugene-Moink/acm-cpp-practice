#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> v(m);
    for (ll i = 0; i < m;i++)
    {
        cin >> v[i].first;
    }
    for (ll i = 0; i < m;i++)
    {
        cin >> v[i].second;
    }

    sort(v.begin(), v.end());
    ll total = 0;
    ll inital_sum = 0;
    for (ll i = 0; i < m;i++)
    {
        ll pos = v[i].first;
        ll cnt = v[i].second;
        if (total < pos - 1)
        {
            cout << "-1" << endl;
            return;
        }

        total += cnt;
        inital_sum += cnt * pos;
    }

    if (total != n)
    {
        cout << "-1" << endl;
        return;
    }

    ll final_sum = n * (n + 1) / 2;
    ll ans = final_sum - inital_sum;
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}