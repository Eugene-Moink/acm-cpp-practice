#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    string s;
    cin >> s;
    ll result = 0;

    for (int i = 0; i < s.size();i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
        {
            result++;
        }
    }

    cout << result << endl;
    return 0;
}