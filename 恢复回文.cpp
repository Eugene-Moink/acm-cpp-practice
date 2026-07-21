#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    ll cnt = 0;
    ll n = s.size() / 2;
    for (ll i = 0; i < n;i++)
    {
        if(s[i]!=s[s.size()-1-i])
            cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    moink();
    return 0;
}