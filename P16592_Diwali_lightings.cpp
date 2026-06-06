#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll countBlue(const string& pattern, ll pos)
{
    ll len = pattern.size();
    ll full = pos / len;
    ll rem = pos % len;

    ll cntB = 0;
    for (int i = 0; i < pattern.size();i++)
    {
        if(pattern[i]=='B')
        {
            cntB++;
        }
    }

    ll extra = 0;
    for (int i = 0; i <= rem - 1;i++)
    {
        if(pattern[i]=='B')
        {
            extra++;
        }
    }

    return full * cntB + extra;
}

int main()
{
    int t;
    cin >> t;
    ll cnt = 0;
    while(t--)
    {
        cnt++;
        string s;
        cin >> s;
        ll i, j;
        cin >> i >> j;

        ll result = countBlue(s, j) - countBlue(s, i - 1);

        cout << "Case #" << cnt << ": " << result << endl;
    }
    return 0;
}