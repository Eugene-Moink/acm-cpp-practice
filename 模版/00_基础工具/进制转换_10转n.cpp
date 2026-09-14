#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

char dig(int d)
{
    if(d<10)
    {
        return '0' + d;
    }
    return 'A' + (d - 10);
}

int main()
{
    ll x, m;
    cin >> x >> m;
    string change="";
    while(x!=0)
    {
        change += dig(x % m);
        x = x / m;
    }
    reverse(change.begin(), change.end());
    cout << change;
    return 0;
}