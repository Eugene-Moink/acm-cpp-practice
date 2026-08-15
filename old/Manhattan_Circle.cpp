#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            cin >> grid[i][j];
        }
    }

    int min_r = n + 1, max_r = 0, min_c = m + 1, max_c = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if(grid[i][j]=='#')
            {
                min_r = min(min_r, i);
                max_r = max(max_r, i);
                min_c = min(min_c, j);
                max_c = max(max_c, j);
            }
        }
    }
    cout << (min_r + max_r) / 2 << " " << (min_c + max_c) / 2 << endl;
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