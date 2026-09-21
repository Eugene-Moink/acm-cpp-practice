#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> ops;
    vector<bool> seen(300005, 0);
    int nq = q;
    while (nq--)
    {
        int x;
        cin >> x;
        ops.push_back(x);
    }

    vector<int> back;
    for (int i = q - 1; i >= 0; i--)
    {
        int cur = ops[i];
        if (!seen[cur])
        {
            seen[cur] = 1;
            back.push_back(cur);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (seen[a[i]])
            continue;

        ans.push_back(a[i]);
    }

    reverse(back.begin(), back.end());
    ans.insert(ans.end(), back.begin(), back.end());
    for (int i = 0; i < (int)ans.size(); i++)
    {
        if (i > 0)
            cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}