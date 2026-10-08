#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> l_r;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);
        l_r.push_back({a, b});
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<int> diff(v.size() + 1, 0);
    for (auto &[l, r] : l_r)
    {
        int L = lower_bound(v.begin(), v.end(), l) - v.begin() + 1;
        int R = lower_bound(v.begin(), v.end(), r) - v.begin() + 1;
        diff[L]++;
        diff[R]--;
    }

    for (int i = 1; i < (int)v.size(); i++)
    {
        diff[i] += diff[i - 1];
    }

    ll ans = 0;
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (diff[i] > 0)
            ans += v[i] - v[i - 1];
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}