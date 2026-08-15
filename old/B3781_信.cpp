#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n,x,y,a,b;
    cin>>n>>x>>y>>a>>b;
    ll joy = 0;           
    ll max_joy = 0;       
    ll consecutive_gift = 0;      
    ll consecutive_no_gift = 0;   
    while(n--)
    {
        ll S, s, M;
        cin >> S >> s >> M;

        ll gift_weight = M - (S * x + s * y);

        if(gift_weight>0)
        {
            joy += gift_weight;

            if(gift_weight>S * x + s * y)
            {
                joy += (ll)ceil(0.5 * gift_weight);
            }

            consecutive_gift++;
            consecutive_no_gift = 0;
            if(consecutive_gift>=a)
            {
                joy *= 2;
            }

            
        }

        else
            {
                consecutive_no_gift++;
                consecutive_gift = 0;

                if (consecutive_no_gift >= b &&joy > 0)
                {
                    joy /= 2;
                }
            }
        max_joy = max(max_joy, joy);
    }
    cout << max_joy << " " << joy << endl;
    return 0;
}