#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 0;
    for (ll i = 0; i < s.size();i++)
    {
        if(s[i]=='(')
            cnt++;
        else
            {
                if(cnt>0)
                {
                    cnt--;
                }
                else
                {
                    ans++;
                }
        }
    }
    cout << ans << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}