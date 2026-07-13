#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    bool result = 1;
    while(n--)
    {
        ll num;
        cin >> num;
        if(num>=0)
        {
            result = 0;
            break;
        }
    }

    if(result)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}