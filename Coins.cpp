#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        
        if(k % 2 == 0)  
        {
            if(n % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else  
        {
            if(n % 2 == 0)  
                cout << "YES" << endl;
            else  
            {
                if(n >= k)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}