#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n;i++)
    {
        string num= to_string(i);
        for (int j = 0; j < num.size(); j++)
        {
            if(num[j]=='0' + k)
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}