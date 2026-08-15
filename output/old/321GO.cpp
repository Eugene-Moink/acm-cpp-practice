#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    while(n)
    {
        cout << n;
        if(n>1)
        {
            cout << ",";
        }
        n--;
    }
    return 0;
}