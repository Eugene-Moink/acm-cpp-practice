#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool is_good(ll num)
{
    string s = to_string(num);
    set<char> digits;
    for(char c : s) {
        digits.insert(c);
        if(digits.size() > 2) return false;
    }
    return true;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll x;
        cin >> x;
        
        
        for(ll y = 2; y <= 1000000000; y++)
        {
            if(!is_good(y)) continue;
            
            ll product = x * y;
            if(is_good(product))
            {
                cout << y << endl;
                break;
            }
        }
    }
    
    return 0;
}