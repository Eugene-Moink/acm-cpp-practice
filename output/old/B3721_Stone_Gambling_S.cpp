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

        bool is_farmer_turn = 1;

        while (a!=0&&b!=0)
        {
            if(is_farmer_turn)
            {
                if(a<b)
                {
                    a++;
                }

                else
                {
                    a /= 2;
                }
            }

            else
            {
                if(b<a)
                {
                    b++;
                }

                else
                {
                    b /= 2;
                }
            }
            is_farmer_turn = !is_farmer_turn;
        }

        cout << a << " " << b << endl;
    }
    return 0;
}