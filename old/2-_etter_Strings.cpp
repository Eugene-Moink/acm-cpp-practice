#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n;i++)
        cin >> s[i];

    ll cnt[11][11] = {0};
    for (int i = 0; i < n;i++)
    {
        cnt[s[i][0] - 'a'][s[i][1] - 'a']++;
    }

    ll ans = 0;
    for (int i = 0; i < 11;i++)
    {
        for (int j = 0; j < 11;j++)
        {
            if(cnt[i][j]==0)
            continue;

            for (int ni = 0; ni < 11;ni++)
            {
                if(ni==i)
                continue;
                ans += cnt[i][j] * cnt[ni][j];
            }
            for (int nj = 0; nj < 11; nj++) 
            {
                if (nj == j) continue;
                ans += cnt[i][j] * cnt[i][nj];
            }
        }
    }
    ans /= 2;
    cout << ans << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        moink();
    }
    return 0;
}