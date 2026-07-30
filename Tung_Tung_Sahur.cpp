#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string p;
    cin >> p;
    string s;
    cin >> s;
    if (p.empty() || s.empty()) 
    {
        cout << "NO" << endl;
        return;
    }
    int i = 0, j = 0;
    while(i<p.size()&&j<s.size())
    {
        if(s[j]!=p[i])
        {
            cout << "NO" << endl;
            return;
        }
        if (j + 1 < s.size() && s[j + 1] == p[i])
        {
            j += 2;
        }
        else
        {
            j++;
        }
        i++;
    }
    if(i==p.size()&&j==s.size())
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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