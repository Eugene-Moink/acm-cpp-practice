#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    auto check = [&](ll h)
    {
        ll water = 0;
        for (int i = 0; i < n;i++)
        {
            if(a[i]<h)
            {
                water += h - a[i];
                if(water>x)
                    return false;
            }
        }
        return (water <= x);
    };

    ll l = 1, r = 2e9;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        if(check(mid))
        {
            l = mid;
        }
        else
            r = mid - 1;
    }
    cout << l << endl;
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