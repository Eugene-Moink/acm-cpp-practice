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
        unordered_set<ll> seen(n);
        vector<ll> result;
        for (int i = 0; i < n;i++)
        {
            ll num;
            cin >> num;

            if (seen.find(num) == seen.end()) 
            {  
                seen.insert(num);                
                result.push_back(num);           
            }
        }

        for (int i = 0; i < result.size(); i++)
        {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
}