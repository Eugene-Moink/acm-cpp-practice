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
    ll last_one = -1;
    for (ll i = 0; i < n;i++)
    {
        if (s[i] == '1')
        {
            last_one = i;
        }
        ans += (last_one + 1);
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}