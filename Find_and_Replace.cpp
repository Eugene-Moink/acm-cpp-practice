#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    bool result_ok = 0;
    for (int start = 0; start <= 1;start++)
    {
        vector<int> mp(26, -1);
        bool ok = 1;
        for (int i = 0; i < n;i++)
        {
            int need = (start + i) % 2;
            int ch = s[i] - 'a';
            if(mp[ch]==-1)
            {
                mp[ch] = need;
            }
            else if(mp[ch]!=need)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            result_ok = 1;
            break;
        }
    }
    cout << (result_ok ? "YES" : "NO") << endl;
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