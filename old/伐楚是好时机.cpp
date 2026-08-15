#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;

    string ans;
    for(char c:s)
    {
        if (c == 'D')
        {
            if(!ans.empty())
            {
                ans.pop_back();
            }
        }
        else
        {
            ans.push_back(c);
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}