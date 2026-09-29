#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, s;
vector<pair<int, int>> pos;
vector<ll> stone, value;

ll calc(ll W)
{
    vector<ll> pref_cnt(n + 1, 0), pref_val(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (stone[i - 1] >= W)
        {
            pref_cnt[i] = pref_cnt[i - 1] + 1;
            pref_val[i] = pref_val[i - 1] + value[i - 1];
        }
        else
        {
            pref_cnt[i] = pref_cnt[i - 1];
            pref_val[i] = pref_val[i - 1];
        }
    }

    ll Y = 0;
    for (auto &p : pos)
    {
        int l = p.first, r = p.second;
        ll cnt = pref_cnt[r] - pref_cnt[l - 1];
        ll val_sum = pref_val[r] - pref_val[l - 1];
        Y += cnt * val_sum;
    }
    return Y;
}

void solve()
{
    cin >> n >> m >> s;
    stone.resize(n);
    value.resize(n);

    ll max_w = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> stone[i] >> value[i];
        max_w = max(max_w, stone[i]);
    }

    pos.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> pos[i].first >> pos[i].second;
    }

    ll lo = 0, hi = max_w + 1;
    ll ans = LLONG_MAX;

    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll Y = calc(mid);
        ans = min(ans, llabs(Y - s));

        if (Y > s)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    for (ll W = max(0LL, lo - 2); W <= lo + 2; W++)
    {
        if (W > max_w + 1)
            break;
        ll Y = calc(W);
        ans = min(ans, llabs(Y - s));
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