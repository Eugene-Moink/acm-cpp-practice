#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> h(n);
        for (int i = 0; i < n;i++)
        {
            cin >> h[i];
        }
        int min_h = *min_element(h.begin(), h.end());
        int max_h = *max_element(h.begin(), h.end());
        
        cout << max_h - min_h + 1 << endl;
    }
    return 0;
}