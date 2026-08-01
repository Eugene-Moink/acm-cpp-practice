#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    vector<string> grid(8);
    for (int i = 0; i < 8;i++)
    {
        cin >> grid[i];
    }

    for (int i = 1; i < 7;i++)
    {
        for(int j = 0; j < 7;j++)
        {
            if (grid[i][j] == '#' &&grid[i + 1][j + 1] == '#' &&grid[i + 1][j - 1] == '#' &&grid[i - 1][j - 1] == '#' &&grid[i - 1][j + 1] == '#')
            {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
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