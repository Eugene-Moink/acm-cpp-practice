#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin >> arr[i][j];
        }
    }

    int result = 0;

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(i+1<n && j+1<m)
            {
                int a11 = arr[i][j];
                int a12 = arr[i][j + 1];
                int a21 = arr[i + 1][j];
                int a22 = arr[i + 1][j + 1];

                if(a11*a22==a12*a21)
                {
                    result++;
                }
            }
        }
    }

    cout << result;
}