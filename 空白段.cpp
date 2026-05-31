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
        int max_cnt = -1;
        for (int i = 1; i <= n;i++)
        {
            int a;
            cin >> a;
            if(a==0)
            {
                cnt++;
            }
            if(a!=0)
            {
                max_cnt = max(cnt, max_cnt);
                cnt = 0;
            }
            max_cnt = max(max_cnt, cnt);
        }
        cout << max_cnt << endl;
    }
    return 0;
}