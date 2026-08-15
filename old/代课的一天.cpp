#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin.ignore();
    getline(cin, s);
    ll ans = 0;
    for (ll i = 0; i < (ll)s.size();i++)
    {
        if (s[i] >= 'A' &&s[i] <= 'Z')
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}