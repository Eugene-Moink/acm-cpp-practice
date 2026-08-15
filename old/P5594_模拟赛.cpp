#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int day_problem[1005][1005] = {0};

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            int day;
            cin >> day;
            day_problem[day][j]=1;
        }
    }
    for (int d = 1; d <= k;d++)
    {
        int cnt = 0;
        for (int q = 1; q <= m;q++)
        {
            if(day_problem[d][q]==1)
            {
                cnt++;
            }
        }
        cout << cnt;
        if (d < k) cout << " ";
    }
    cout << endl;
    return 0;
}