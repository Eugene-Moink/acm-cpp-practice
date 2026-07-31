#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (j < m &&(s[i] == t[j] || s[i] == '?'))
        {
            if (s[i] == '?')
                {
                    s[i] = t[j];
                }

                j++;
        }

        else if (s[i] == '?')
        {
            s[i] = 'a';
        }
        
    }

    if (j == m)
    {
        cout << "Yes" << endl;
        cout << s << endl;
    }
    else
    {
        cout << "No" << endl;
    }
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