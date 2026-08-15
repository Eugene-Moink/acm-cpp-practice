#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll n;
char path[12];

void dfs(ll step)
{
    if (step == n)
    {
        for (ll i = 0; i < n;i++)
        {
            cout << path[i];
            // if (i < n - 1)
            // {
            //     cout << " ";
            // }
        }
        cout << endl;
        return;
    }

    char choices[2] = {'N', 'Y'};
    for (ll i = 0; i < 2;i++)
    {
        path[step] = choices[i];
        dfs(step + 1);
    }
}

void solve()
{
    cin >> n;
    dfs(0);
}

int main()
{
    solve();
    return 0;
}