#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, d;
    cin >> n >> d;

    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        bool ok = true;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (abs(x[i] - x[j]) < d)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
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