#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    getline(cin, s);
    unordered_set<char> moink;
    for (ll i = 0; i < s.size();i++)
    {
        if (s[i] >= 'a' &&s[i] <= 'z')
        {
            moink.insert(s[i]);
        }
    }
    cout<<moink.size()<<endl;
}

int main()
{
    moink();
    return 0;
}