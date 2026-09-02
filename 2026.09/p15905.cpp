#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<ll> others, pigs;

    for (int i = 0; i < n; i++)
    {
        string s;
        ll inf;
        cin >> s >> inf;
        if (s == "pig")
            pigs.push_back(inf);
        else
            others.push_back(inf);
    }

    sort(others.begin(), others.end());
    vector<ll> pref(others.size() + 1, 0);
    for (int i = 1; i <= (int)others.size(); i++)
    {
        pref[i] = pref[i - 1] + others[i - 1];
    }

    ll ans = 0;
    for (ll p : pigs)
    {
        int idx = lower_bound(others.begin(), others.end(), p) - others.begin();
        ll sum = p + pref[idx];
        ans = max(ans, sum);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}