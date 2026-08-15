#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));

    for (int i = 0; i < h; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < w; j++)
        {
            grid[i][j] = row[j];
        }
    }

    bool found = 0;
    ll top = h, bottom = -1, left = w, right = -1;

    for (int i = 0; i < h && !found; i++)
    {
        for(int j = 0; j < w;j++)
        {
            if(grid[i][j]=='#')
            {
                top = i;
                found = 1;
                break;
            }
        }
    }

    found = 0;

    for (int i = h - 1; i >= 0 && !found; i--)
    {
        for(int j = 0; j < w; j++)
        {
            if(grid[i][j]=='#')
            {
                bottom = i;
                found = 1;
                break;
            }
        }
    }

    found = 0; 

    for (int j = 0; j < w && !found; j++)
    {
        for (int i = 0; i < h; i++)
        {
            if (grid[i][j] == '#')
            {
                left = j;    
                found = 1;
                break;       
            }
        }
    }   

    found = 0; 

    for (int j = w - 1; j >= 0 && !found; j--)
    {
        for (int i = 0; i < h; i++)
        {
            if (grid[i][j] == '#')
            {
                right = j;   
                found = 1;
                break;
            }
        }
    }

    for (int i = top; i <= bottom; i++) 
    {
        for (int j = left; j <= right; j++) 
        {
            cout << grid[i][j]; 
        }
        cout << endl;
    }
    return 0;
}