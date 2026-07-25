#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt_black = 0;
    for (ll i = 0; i < s.size();i++)
    {
        if (s[i] == 'B')
        {
            cnt_black++;
        }
        else
        {
            ans += cnt_black;
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}