#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, k;
    string s;
    cin >> n >> k >> s;
    if (n == 0 || k > n)
    {
        cout << "0" << endl;
        return;
    }

    ll cnt = 0;
    ll ans = 0;
    for (ll i = 0; i < n;i++)
    {
        if (cnt == k)
        {
            ans++;
            cnt = 0;
        }

        if (s[i] == 'O')
        {
            cnt++;
        }

        if (s[i] == 'X')
        {
            cnt = 0;
        }
    }
    if (cnt == k) ans++;
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}