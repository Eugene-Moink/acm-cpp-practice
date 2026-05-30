#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll total = 0;
        for (int i = 1; i <= n;i++)
        {
            ll num;
            cin >> num;
            total += num;
        }

        ll k = sqrtl(total);
        if(k*k==total)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}