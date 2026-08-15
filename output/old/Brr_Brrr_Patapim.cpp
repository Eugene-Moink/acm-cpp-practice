#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<int> ans(2 * n + 1);
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            ans[i + j + 2] = grid[i][j];
        }
    }

    vector<bool> seen(2 * n + 1, 0);
    for (int i = 2; i <= 2 * n;i++)
    {
        seen[ans[i]] = 1;
    }

    for (int x = 1; x <= 2 * n;x++)
    {
        if(!seen[x])
        {
            ans[1] = x;
            break;
        }
    }

    for (int i = 1; i <= 2 * n;i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}