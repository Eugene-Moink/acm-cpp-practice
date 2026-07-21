#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll m, n;
    cin >> m >> n;
    vector<ll> sc(m), st(n);
    for (ll i = 0; i < m;i++)
    {
        cin >> sc[i];
    }
    sort(sc.begin(), sc.end());

    for (ll i = 0; i < n;i++)
    {
        cin >> st[i];
    }

    ll ans = 0;
    for (ll x : st)
    {
        auto it = lower_bound(sc.begin(), sc.end(), x);
        ll min_num = LLONG_MAX;
        if (it != sc.end())
        {
            ll temp = *it - x;
            min_num = min(min_num, temp);
        }
        if (it != sc.begin())
        {
            auto it_prev = it;
            ll temp = x - *(--it_prev);
            min_num = min(min_num, temp);
        }
        ans += min_num;
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}