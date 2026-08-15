#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    string s;
    cin >> s;
    string num = "";
    for (ll i = 0;i<s.size();i++)
    {
        if (s[i] >= '0' &&s[i] <= '9')
        {
            num += s[i];
        }
    }
    cout << num << endl;
    return 0;
}