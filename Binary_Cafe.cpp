#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n,k;
    cin >> n >> k;

    ll price = 1;
    ll current = 0;
    while(k--)
    {
        if(price>n)
        {
            break;
        }

        current += price;
        price *= 2;
    }
    ll ans = min(current, n);
    cout << ans + 1 << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}