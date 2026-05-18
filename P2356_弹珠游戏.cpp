#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    int cnt = 0;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            cin >> arr[i][j];

            if(arr[i][j]!=0)
            {
                cnt++;
            }
        }
    }

    
    if(cnt==n*n)
    {
        cout << "Bad Game!" << endl;
        return 0;
    }

    vector<int> row_sum(n, 0);
    vector<int> col_sum(n, 0);

    for (int i = 0; i < n;i++)
    { 
        for (int j = 0; j < n;j++)
        {
            if(arr[i][j]>0)
            {
                row_sum[i] += arr[i][j];
                col_sum[j] += arr[i][j];
            }
        }
    }

    int max_score = 0;
    for (int i = 0; i < n;i++)
    { 
        for (int j = 0; j < n;j++)
        {
            if(arr[i][j]==0)
            {
                int now_score = row_sum[i] + col_sum[j];
                max_score = max(max_score, now_score);
            }
        }
    }

    cout << max_score << endl;
    return 0;
}