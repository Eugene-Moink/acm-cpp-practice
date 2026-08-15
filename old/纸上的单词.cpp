#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<string> s(8);
        for (int i = 0; i < 8;i++)
        {
            cin >> s[i];
        }

        string result = "";
        for (int i = 0; i < 8;i++)
        {
            for (int j = 0; j < 8;j++)
            {
                if(s[i][j]!='.')
                    result += s[i][j];
            }
        }
        cout << result << endl;
    }
    return 0;
}