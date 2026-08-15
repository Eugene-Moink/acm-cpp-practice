#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s = "codeforces";
        string str;
        cin >> str;
        int cnt = 0;

        for (int i = 0; i < s.size();i++)
        {
            if(s[i]!=str[i])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}