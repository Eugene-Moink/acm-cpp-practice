#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll>w(n+1);
    for (ll i = 1; i <= n;i++)
    {
        cin >> w[i];
    }

    if (n % 2 == 1)
    {
        cout << "No" << endl;
        return;
    }

    ll odd_min = LLONG_MAX;
    ll even_max = LLONG_MIN;
    for (ll i = 1; i <= n;i++)
    {
        if(i%2==0)
        {
            even_max = max(even_max, w[i]);
        }
        else
        {
            odd_min = min(odd_min, w[i]);
        }
    }

    if (even_max + 2 <= odd_min)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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