#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll> p(n);
        for (int i = 0; i < n;i++)
        {
            cin >> p[i];
        }

        for (int i=0; i<n; ++i) 
        {
            if (i) cout << ' ';
            cout << n+1-p[i];
        }
        cout << endl;
    }
    return 0;
}