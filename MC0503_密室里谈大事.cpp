#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll a = 0, b = 0, c = 0, d = 0;

    while(n--)
    {
        ll s;
        cin >> s;
        if(s>=90)
            a++;

        else if(s>=80 && s<=89)
            b++;

        else if(s>=60 && s<=79)
            c++;

        else if(s<60)
        {
            d++;
        }
    }

    cout << d << " " << c << " " << b << " " << a << endl;
    return 0;
}