#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;

        for (ll i = n + 1; i <= 2 * n; i++)
        {
            cout << i;
            if (i != 2 * n) cout << " ";
        }
        cout << endl;
    }
    return 0;
}