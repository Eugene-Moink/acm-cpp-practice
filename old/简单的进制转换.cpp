#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll sum = 0;
    for (ll i = 0; i < s.size();i++)
    {
        if (s[i] == '1') 
        {
            sum += (1LL << i);
        }
    }
    cout << sum << endl;
}

int main()
{
    moink();
    return 0;
}