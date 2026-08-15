#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    int res = 1;
    bool ex = 0;
    int n = (int)s.size();
    for (int i = 0; i + 1 < n;i++)
    {
        if (s[i] != s[i + 1])
        {
            res += (s[i] != s[i + 1]);
            ex |= (s[i] == '0' && s[i + 1] == '1');
        }
    }
    cout << res - ex << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}