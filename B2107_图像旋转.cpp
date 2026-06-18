#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(m));
    vector<vector<ll>> new_arr(m, vector<ll>(n));
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int k = 0; k < n;k++)
    {
        for (int l = 0; l < m;l++)
        {
            new_arr[l][n-1-k] = arr[k][l]; 
        }
    }

    for (int i = 0; i < m;i++)
    {
        for (int j = 0; j < n;j++)
        {
            cout << new_arr[i][j];
            if (j != n - 1)
            {
                cout << " ";
            }
        }
         cout << endl;
    }

        return 0;
}