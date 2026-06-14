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
        ll a, b;
        cin >> a >> b;
        if ((a + b) % 2 == 0)  
        {
            ll op1 = a + b;  
            ll max_val = op1;  
            
            
            for(ll k = 1; k * k <= b; k++)
            {
                if (b % k == 0)
                {
                    ll new_a = a * k;
                    ll new_b = b / k;
                    ll new_sum = new_a + new_b;
                    
                    if (new_sum % 2 == 0)
                    {
                        max_val = max(max_val, new_sum);
                    }
                    
                    ll k2 = b / k;
                    if (k2 != k) 
                    {
                        new_a = a * k2;
                        new_b = b / k2;
                        new_sum = new_a + new_b;
                        
                        if (new_sum % 2 == 0) 
                        {
                            max_val = max(max_val, new_sum);
                        }
                    }
                }
            }
            cout << max_val << endl;
        }
        else
        {
            if (a % 2 == 0 &&b % 2 == 1)
            {
                cout << "-1" << endl; 
            }
            else if(a % 2 == 1 &&b % 2 == 0)
            {
                if (b % 4 == 0)
                {
                    ll a1 = a * 2;
                    ll b1 = b / 2;
                    cout << a1 + b1 << endl;
                }
                else
                {
                    cout << "-1" << endl;
                }
            }
            else
            {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}