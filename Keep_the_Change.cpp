#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;

    ll ans = 0;
    while(n--)
    {
        ll a, b;
        string s;
        cin >> a >> b >> s;

        if(s=="keep")
        {
            ans += (b - a);
        }
    }

    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}