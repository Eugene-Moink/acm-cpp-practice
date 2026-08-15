#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h;i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w;j++)
        {
            if(grid[i][j] == '#')
            {
                bool ok = 0;
                if (i > 0 && grid[i - 1][j] == '#')
                {
                    ok = 1;
                }
                if (i < h - 1 && grid[i + 1][j] == '#')
                {
                    ok = 1;
                }
                if(j > 0 && grid[i][j - 1] == '#')
                {
                    ok = 1;
                }
                if(j < w - 1 && grid[i][j + 1] == '#')
                {
                    ok = 1;
                }
                if(!ok)
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    moink();
    return 0;
}