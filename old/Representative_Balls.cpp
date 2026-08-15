#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> max_size(m + 1, -1);

    for (ll i = 1; i <= n; i++)
    {
        ll color, size;
        cin >> color >> size;
        if(size>max_size[color])
        {
            max_size[color] = size;
        }
    }

    for (ll i = 1; i <= m;i++)
    {
        cout << max_size[i];
        if (i < m)
        {
            cout << " ";
        }
    }
    return 0;
}