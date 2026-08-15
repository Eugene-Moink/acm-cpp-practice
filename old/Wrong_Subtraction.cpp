#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    while(k--)
    {
        if(n%10!=0)
        {
            n--;
        }
        else
        {
            n /= 10;
        }
    }
    cout << n << endl;
    return 0;
}