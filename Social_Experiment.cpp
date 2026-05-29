#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        if(n==2)
        {
            cout << "2" << endl;
        }
        else if(n==3)
        {
            cout << "3" << endl;
        }
        else if(n%2==0&&n>=4)
        {
            cout << "0" << endl;
        }
        else if(n%2!=0&&n>=5)
        {
            cout << "1" << endl;
        }
    }
    return 0;
}