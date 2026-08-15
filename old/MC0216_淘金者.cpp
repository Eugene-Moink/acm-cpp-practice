#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    string s;
    cin >> s;
    char find;
    cin >> find;
    bool result = 0;

    for (int i = 0; i < s.size();i++)
    {
        if(s[i]==find)
        {
            result = 1;
            cout << i + 1;
            break;
        }
    }

    if(!result)
    {
        cout << "-1";
    }
    return 0;
}