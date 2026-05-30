#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(a==b)
        {
            cout << c << endl;
        }

        else if(a==c)
        {
            cout << b << endl;
        }

        else if(b==c)
        {
            cout << a << endl;
        }
        cout << endl;
    }
    return 0;
}