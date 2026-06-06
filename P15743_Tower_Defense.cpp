#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n, m, h;
    cin >> n >> m >> h;

    vector<ll> diff(m + 2, 0);
    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    ll cur = 0;
    vector<ll> damage(m + 1, 0);
    for (int i = 1; i <= m - 1;i++)
    {
        cur += diff[i];
        damage[i] = cur;
    }

    for (int i = m - 1; i >= 1;i--)
    {
        h -= damage[i];
        if(h<=0)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}