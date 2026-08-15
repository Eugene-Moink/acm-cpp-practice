#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    ll cnt = 0;
    for (ll i = 0; i < n;i++)
    {
        ll x;
        cin >> x;
        if (x == -1) cnt++;
    }
        if (n % 2 == 0)
        {
            if (cnt % 2 == (n / 2) % 2)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
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