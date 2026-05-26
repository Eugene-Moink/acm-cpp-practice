#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll zheng = 0;
    ll fu = 0;

    while(n--)
    {
        ll number;
        cin >> number;
        if(number>0)
        {
            zheng++;
        }
        else if(number<0)
            fu++;
    }

    cout << zheng << " " << fu << endl;
    return 0;
}