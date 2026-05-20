#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int pos[15][25];

    int K, N;
    cin >> K >> N;

    for (int i = 1; i <= K;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            int cow;
            cin >> cow;
            pos[i][cow] = j;
        }
    }

    int ans = 0;

    for (int a = 1; a <= N;a++)
    {
        for (int b = a + 1; b <= N;b++)
        {
            bool first = (pos[1][a] < pos[1][b]);
            bool ok = true;

            for (int i = 2; i <= K; i++) 
            {
                bool now = (pos[i][a] < pos[i][b]);
                if (now != first) 
                { 
                    ok = false;
                    break;
                }
            }
             if (ok) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}