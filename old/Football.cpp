#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll max_sc = 0;
    string team = "";

    ll n;
    cin >> n;
    unordered_map<string, ll> mp;
    for (ll i = 0; i < n;i++)
    {
        string s;
        cin >> s;
        mp[s]++;

        if(mp[s]>max_sc)
        {
            max_sc = mp[s];
            team = s;
        }
    }
    cout << team << endl;
    ;
}

int main()
{
    moink();
    return 0;
}