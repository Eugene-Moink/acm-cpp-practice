#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a = 0;
        int b = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.size();i++)
        {
            if(s[i]=='A')
            {
                a++;
            }
            else if(s[i]=='B')
            {
                b++;
            }
        }
         if(a>b)
            {
                cout << "A" << endl;
            }
            else
            {
                cout << "B" << endl;
            }
    }
    return 0;
}