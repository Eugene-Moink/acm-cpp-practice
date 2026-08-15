#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    cin >> n >> m;
    bool ok = 0;
    vector<int> num(n, -1);
    while(m--)
    {
        int s, c;
        cin >> s >> c;
        s--;
        if(num[s] != -1&&num[s] != c)
        {
            cout << -1 << '\n';
            return; 
        }
        num[s] = c;
    }
    
    if(n > 1 && num[0] == 0)
    {
        cout << -1 << '\n';
        return;
    }

    string ans = "";
    for (int i = 0; i < n; ++i)
    {
        if(num[i] != -1)
        {
            ans.push_back('0' + num[i]);
        }
        else
        {
            if(i == 0 && n > 1)
            {
                ans.push_back('1');
            }
            else
            {
                ans.push_back('0');
            }
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}