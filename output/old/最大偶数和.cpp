#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while(t--)
    {
        ll b, a;  
        cin >> b >> a;
        
        ll sol = -1;
        
       
        if ((a + b) % 2 == 0) 
        {
            sol = a + b;
        }
        
        if (a % 2 == 1 && b % 2 == 1) 
        {
            sol = max(sol, a * b + 1);
        }
        
        else if (a % 2 == 0 && (a % 4 == 0 || b % 2 == 0)) 
        {
            sol = max(sol, 2 + (a * b) / 2);
        }
        
        cout << sol << endl;
    }
    return 0;
}