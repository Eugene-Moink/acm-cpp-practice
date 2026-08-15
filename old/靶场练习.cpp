#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        vector<string> s(10);
        for (int i = 0; i < 10;i++)
        {
            cin >> s[i];
        }

        ll ans = 0;
        for (int i = 0; i < 10;i++)
        {
            for (int j = 0; j < s[i].size();j++)
            {
                if(s[i][j]=='X')
                {
                    int d = min({i, j, 9 - i, 9 - j});
                    ans += d + 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}