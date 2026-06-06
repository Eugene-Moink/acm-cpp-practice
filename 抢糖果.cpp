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
        ll odd = 0;
        ll even = 0;

        for (int i = 1; i <= n;i++)
        {
            ll num;
            cin >> num;
            if(num%2==0)
            {
                even += num;
            }
            else
            {
                odd += num;
            }
        }
        if(even>odd)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}