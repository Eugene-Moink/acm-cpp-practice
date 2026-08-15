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

    for (int i = 0; i < 8;i++)
    {
        bool b = 1;
        for (int j = 0; j < 8;j++)
        {
            if(grid[i][j]!='R')
            {
                b = 0;
                break;
            }
        }
        if(b)
        {
            cout << "R" << endl;
            return;
        }
    }
    cout << "B" << endl;
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