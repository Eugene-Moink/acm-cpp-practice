#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    vector<int> v;
    vector<pair<int, int>> intervals;
    int n;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
        v.push_back(a);
        v.push_back(b);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<int> diff(v.size() + 1, 0);
    for (auto &[a, b] : intervals)
    {
        int L = lower_bound(v.begin(), v.end(), a) - v.begin();
        int R = lower_bound(v.begin(), v.end(), b) - v.begin();
        diff[L]++;
        diff[R]--;
    }

    for (int i = 1; i < (int)v.size(); ++i)
    {
        diff[i] += diff[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i + 1 < (int)v.size(); i++)
    {
        if (diff[i] > 0)
            ans += v[i + 1] - v[i];
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