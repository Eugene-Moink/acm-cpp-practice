#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    ll n = s.size();

    unordered_set<string> ans;
    for (ll i = 0; i < n;i++)
    {
        string sub = "";
        for (ll j = i; j < n;j++)
        {
            sub += s[j];
            ans.insert(sub);
        }
    }
    cout << ans.size() << endl;
}

int main()
{
    moink();
    return 0;
}