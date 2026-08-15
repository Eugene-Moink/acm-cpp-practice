#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    ll sum = 0;
    for (ll i = 1;;i++)
    {
        sum += i;
        if (sum >= n)
        {
            cout << i << endl;
            return;
        }
    }
}

int main()
{
    moink();
    return 0;
}