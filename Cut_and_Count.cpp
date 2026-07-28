#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (ll cnt = 1; cnt < n;cnt++)
    {
        vector<bool> left(26, 0), right(26, 0);
        for (ll i = 0; i < cnt;i++)
        {
            left[s[i] - 'a'] = 1;
        }
        for (ll i = cnt; i < n;i++)
        {
            right[s[i] - 'a'] = 1;
        }
        ll temp = 0;
        for (ll i = 0; i < 26;i++)
        {
            if(left[i]&&right[i])
            {
                temp++;
            }
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}