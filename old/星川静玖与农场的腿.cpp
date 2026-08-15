#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 0; i <= n/2;i++)
        {
            for (int j = 0; j <= n/4;j++)
            {
                bool ok = 0;
                if (i * 2 + j * 4 == n)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}