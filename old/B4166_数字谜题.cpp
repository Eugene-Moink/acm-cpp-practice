#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        ll num;
        cin >> num;

        ll cur = 0, best = 0;
        while(num>0)
        {
            if(num & 1LL)
            {
                cur++;
                best = max(best, cur);
            }
            else
                {
                    cur = 0;
                }
                num >>= 1;
        }
        cout << best << endl;
    }
    return 0;
}