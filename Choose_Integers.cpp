#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (c % __gcd(a, b) == 0)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}

int main()
{
    moink();
    return 0;
}