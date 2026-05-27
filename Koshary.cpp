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
        int x, y;
        cin >> x >> y;

        bool to_x = 0, to_y = 0;
        if(x%2==0)
        {
            to_x = 1;
        }

        if(y%2==0)
        {
            to_y = 1;
        }

        if (to_x == 0 && to_y == 0)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}