#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    if(n==1)
    {
        ll num;
        cin >> num;
        cout << num;
        return 0;
    }
    for (int i = 1; i <= n;i++)
    {
        ll num;
        cin >> num;
        if(i<n)
        {
            cout << num << ",";
        }
        if(i==n)
        {
            cout << num;
        }
    }
    return 0;
}