#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
        ll n;
        cin>>n;
        set<ll> arr;
        
        for (int i = 0; i < n;i++)
        {
            ll num;
            cin >> num;
            arr.insert(num);
        }

        if(arr.size()==n)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
   }
   return 0;
}