#include<bits/stdc++.h>
#define endl "\n"
#define mod 998244353
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;

    ll result = 1;
    for (int i = 1; i <= n;i++)
    {
        ll number;
        cin >> number;
        result = ((number % mod) * (result % mod)) % mod;
    }
    cout << result << endl;
    return 0;
}