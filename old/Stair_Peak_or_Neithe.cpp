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
        vector<ll> num(3);
        for (int i = 0; i < 3;i++)
        {
            cin >> num[i];
        }

        if(num[2]>num[1] && num[1]>num[0])
        {
            cout << "STAIR" << endl;
        }

        else if(num[2]<num[1] && num[1]>num[0])
        {
            cout << "PEAK" << endl;
        }

        else
        {
            cout << "NONE" << endl;
        }
    }
    return 0;
}