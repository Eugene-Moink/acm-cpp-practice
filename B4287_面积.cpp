#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long result_aera = 0;

    long long result[101][101] = {0};
    while(n--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i < x2;i++)
        {
            for (int j = y1; j < y2;j++)
            {
                if (!result[i][j])
                 {
                    result[i][j] = true;
                    result_aera++;
                 }
            }
        }

    }

    cout << result_aera << endl;
    return 0;
}