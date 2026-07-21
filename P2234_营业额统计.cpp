#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    set<ll>num;
    ll ans = 0;

    ll first;
    cin >> first;
    num.insert(first);
    ans += first;

    for (ll i = 1; i < n;i++)
    {
        ll x;
        cin >> x;
        auto it = num.lower_bound(x);

        ll minDiff = LLONG_MAX;
        if (it != num.end()) 
        {
            minDiff = min(minDiff, *it - x);
        }

        if (it != num.begin()) 
        {
            auto itPrev = it; 
            --itPrev;         
            minDiff = min(minDiff, x - *itPrev);
        } 

        ans += minDiff;
        num.insert(x);
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}