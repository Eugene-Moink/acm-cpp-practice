#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }

    int n;
    cin >> n;

    bool seen[105] = {false};
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        seen[b] = 1;
    }

    bool ok = 0;
    for (int i = 0; i < 3; i++)
    {
        if (seen[a[i][0]] && seen[a[i][1]] && seen[a[i][2]])
        {
            ok = 1;
        }

        if (seen[a[0][i]] && seen[a[1][i]] && seen[a[2][i]])
        {
            ok = 1;
        }
    }

    if ((seen[a[0][0]] && seen[a[1][1]] && seen[a[2][2]]) || (seen[a[0][2]] && seen[a[1][1]] && seen[a[2][0]]))
    {
        ok = 1;
    }

    if (ok)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}