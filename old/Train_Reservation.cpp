#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    char x;
    cin >> n >> x;
    ll idx = x - 'A';

    bool found = 0;
    for (ll i = 1; i <= n;i++)
    {
        string s;
        cin >> s;

        if(s[idx]=='o')
        {
            cout << "Yes" << endl;
            found = 1;
            break;
        }
    }

    if(!found)
    {
        cout << "No" << endl;
    }
    return 0;
}