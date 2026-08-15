#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll T;
    cin >> T;
    while(T--)
    {
        ll n;
        cin >> n;

        for (int i = 0; i <= n-1;i++)
        {
            ll small = i + 1;
            ll median = 3 * n - 2 * i - 1;
            ll big = 3 * n - 2 * i;

            cout << small << " " << median << " " << big << " ";
        }
        cout << endl;
    }
    return 0;
}