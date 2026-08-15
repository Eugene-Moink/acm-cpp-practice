#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll n, k;
ll path[10];

void dfs(ll step)
{
    if (step == n)
    {
        for (ll i = 0; i < n;i++)
        {
            cout << path[i];
            if (i < n - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
        return;
    }

    for (ll i = 1; i <= k;i++)
    {
        path[step] = i;
        dfs(step + 1);
    }
}

void solve()
{
    cin >> n >> k;
    dfs(0);
}

int main()
{
    solve();
    return 0;
}