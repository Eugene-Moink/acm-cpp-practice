#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll T;
    cin >> T;
    while(T--)
    {
        int n, k;
        cin >> n >> k;

        ll sum = 0;
        for (int i = 0; i < n;i++)
        {
            ll x;
            cin >> x;
            sum += x;
        }

        if((sum%2==1)||(n*k)%2==0)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}