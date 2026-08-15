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

    bool seen[26] = {0};
    ll ans = s.size();

    for (ll i = 0; i < s.size();i++)
    {
        ll idx = s[i] - 'A';
        if(seen[idx]==0)
        {
            ans++;
            seen[idx] = 1;
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