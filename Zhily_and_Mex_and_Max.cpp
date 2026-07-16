#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    ll max_num = -1;
    vector<ll> cnt(n + 2, 0);
    vector<ll> order;
    unordered_map<ll, ll> total;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        max_num = max(max_num, x);
        total[x]++;
        if (x <= n + 1) cnt[x]++;
    }

    ll mex_all = 0;
    while (cnt[mex_all] > 0) mex_all++;

    order.push_back(max_num);
    total[max_num]--;
    if (total[max_num] == 0) total.erase(max_num);

    for (ll i = 0; i < mex_all; i++)
    {
        if (i == max_num) continue;
        order.push_back(i);
        total[i]--;
        if (total[i] == 0) total.erase(i);
        cnt[i]--;
    }

    for (auto &p : total)
    {
        while (p.second > 0)
        {
            order.push_back(p.first);
            p.second--;
        }
    }

    ll ans = 0;
    vector<bool> seen(n + 2, 0);
    ll current_max = max_num;
    ll current_mex = 0;
    for (ll i = 0; i < order.size(); i++)
    {
        ll x = order[i];
        if (x <= n + 1) seen[x] = 1;
        if (x == current_mex)
        {
            while (current_mex < seen.size() && seen[current_mex] == 1)
                current_mex++;
        }
        ans += current_max + current_mex;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}