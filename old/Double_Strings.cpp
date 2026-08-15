#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<string> s(n);
    unordered_set<string> str;

    for (int i = 0; i < n;i++)
    {
        cin >> s[i];
        string temp = s[i];
        str.insert(temp);
    }

    for (int i = 0; i < n;i++)
    {
        bool ok = 0;
        int len = s[i].size();

        for (int j = 1; j < len;j++)
        {
            string l = s[i].substr(0, j);
            string r = s[i].substr(j, len - j);

            if(str.count(l)&&str.count(r))
            {
                ok = 1;
            }
        }
        if(ok)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
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