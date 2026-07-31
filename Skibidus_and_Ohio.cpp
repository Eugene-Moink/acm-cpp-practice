#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    int n = s.size();
    bool ok = 0;
    for (int i = 0; i < n - 1;i++)
    {
        if (s[i] == s[i + 1])
        {
            ok = 1;
            break;
        }
    }
    if(ok)
        cout << 1 << endl;
    else
        cout << n << endl;
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