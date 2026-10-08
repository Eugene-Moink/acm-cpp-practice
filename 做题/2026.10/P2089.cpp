#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> ans;
int cur[11];
int sum = 0;
int n;

void dfs(int pos, int sum)
{
    if (pos > 10)
    {
        if (sum == n)
        {
            vector<int> tmp;
            for (int i = 1; i <= 10; i++)
                tmp.push_back(cur[i]);
            ans.push_back(tmp);
        }

        return;
    }

    for (int x = 1; x <= 3; x++)
    {
        cur[pos] = x;
        dfs(pos + 1, sum + x);
    }
}

void solve()
{

    cin >> n;
    if (n > 30)
    {
        cout << 0;
        return;
    }

    dfs(1, 0);

    int m = ans.size();
    cout << m << '\n';
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}