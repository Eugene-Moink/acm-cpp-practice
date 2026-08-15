#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
const ll mod = 2026;

void moink()
{
    ll n;
    cin >> n;
    ll result = 1;
    for (ll i = 2; i <= n;i++)
    {
        result = (result * i) % mod;
    }
    cout << result << endl;
}

int main()
{
    moink();
    return 0;
}