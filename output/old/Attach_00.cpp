#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll k;
        cin >> k;
        for (ll i = 1; i <= 100; i++)
        {
            ll n = k * i;
            string s = to_string(n);
            if(s.find("00") != string::npos)
            {
                cout << n << endl;
                break;
            }
        }
    }
    return 0;
}