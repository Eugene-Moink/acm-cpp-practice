#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        vector<string> s(3);
        for (int i = 0; i < 3;i++)
        {
            cin >> s[i];
        }

        for (int i = 0; i < 3;i++)
        {
            bool a = 0, b = 0, c = 0;
            if(s[i].find('?')==string::npos)
            {
                continue;
            }
            for (char ch : s[i])
            {
                if(ch=='A')
                {
                    a = 1;
                }
                if(ch=='B')
                {
                    b = 1;
                }
                if(ch=='C')
                {
                    c = 1;
                }
            }
            if(!a)
            {
                cout << "A" << endl;
            }
            else if(!b)
            {
                cout << "B" << endl;
            }
            else
            {
                cout << "C" << endl;
            }
        }
    }
    return 0;
}