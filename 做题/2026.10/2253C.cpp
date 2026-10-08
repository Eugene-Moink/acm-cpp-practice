#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(x), b(y);
    for (int &val : a)
        cin >> val;
    for (int &val : b)
        cin >> val;

    vector<int> c, d, e;
    int i = 0, j = 0;

    while (i < (int)a.size() && j < (int)b.size())
    {
        if (a[i] == b[j])
        {
            c.push_back(a[i]);
            i++, j++;
        }
        else if (a[i] < b[j])
        {
            d.push_back(a[i]);
            i++;
        }
        else
        {
            e.push_back(b[j]);
            j++;
        }
    }
    while (i < (int)a.size())
    {
        d.push_back(a[i]);
        i++;
    }
    while (j < (int)b.size())
    {
        e.push_back(b[j]);
        j++;
    }

    vector<int> ans;

    int take_d = min((int)d.size(), n);
    for (int k = (int)d.size() - take_d; k < (int)d.size(); k++)
        ans.push_back(d[k]);

    int take_e = min((int)e.size(), m);
    for (int k = (int)e.size() - take_e; k < (int)e.size(); k++)
        ans.push_back(e[k]);

    for (int val : c)
        ans.push_back(val);

    sort(ans.rbegin(), ans.rend());
    ll res = 0;
    int limit = min(n + m - 1, (int)ans.size());
    for (int k = 0; k < limit; k++)
        res += ans[k];

    cout << res << '\n';
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