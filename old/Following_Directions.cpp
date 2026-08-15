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
        string s;
        cin >> n >> s;
        ll x = 0, y = 0;
        bool ok = 0;
        for (int i = 0;i<s.size();i++)
        {
            if(s[i]=='L')
            {
                x--;
            }

            if(s[i]=='R')
            {
                x++;
            }

            if(s[i]=='U')
            {
                y++;
            }
            
            if(s[i]=='D')
            {
                y--;
            }

            if (x == 1 && y == 1)
            {
                ok = 1;
            }
        }
       cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}