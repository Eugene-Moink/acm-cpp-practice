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
        ll a, b, x;
        cin >> a >> b >> x;

        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }

        if(x==1)
        {
            cout << abs(a - b) << endl;
            continue;
        }

        if (a > b) 
        {
            ll operations = 0;
            while (a > b) 
            {
                if (a % x == 0) 
                {
                    a /= x;
                    operations++;
                } 
                else 
                {
                    ll remainder = a % x;
                    ll needed = x - remainder;
                    operations += needed;
                    a += needed;
                }
            }
            operations += (b - a); 
            cout << operations << endl;
            continue;
        }
        cout << (b - a) << endl;
    }
    return 0;
}