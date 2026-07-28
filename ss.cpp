#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    ll n = s.size();
    for (ll len = n - 2; len >= 2;len-=2)
    {
        ll half = len / 2;
        bool ok = 1;
        for (ll i = 0; i < half;++i)
        {
            if(s[i]!=s[half+i])
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            cout << len << endl;
            return;
        }
    }
}

int main()
{
    moink();
    return 0;
}