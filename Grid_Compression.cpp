#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll h, w;
    cin >> h >> w;
    vector<string> grid(h + 1);
    for (ll i = 1; i <= h;i++)
    {
        cin >> grid[i];
    }

    vector<bool> row(h + 1, 0);
    vector<bool> col(w + 1, 0);
    for (ll i = 1; i <= h; i++)
    {
        for (ll j = 1; j <= w;j++)
        {
            if(grid[i][j-1]=='#')
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 1; i <= h; i++) 
        {
        if (!row[i]) continue;  
        for (int j = 1; j <= w; j++) 
        {
            if (!col[j]) continue; 
            cout << grid[i][j-1];
        }
        cout << endl;
    }
}

int main()
{
    moink();
    return 0;
}