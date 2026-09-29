#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    map<int, int> cnt;
    for (int x : a)
        cnt[x]++;

    vector<int> vals;
    for (auto &p : cnt)
        vals.push_back(p.first);
    sort(vals.rbegin(), vals.rend());

    vector<int> ans;
    for (int v : vals)
    {
        ans.push_back(v);
        cnt[v]--;
    }

    while ((int)ans.size() < n)
    {
        for (int v : vals)
        {
            if (cnt[v] > 0)
            {
                ans.push_back(v);
                cnt[v]--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}