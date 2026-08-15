#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll n, k;
ll path[15];
ll used[15];

void dfs(ll step)
{
    if (step == k)
    {
        for (ll i = 0; i < k;i++)
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

    for (ll i = 1; i <= n;i++)
    {
       if (used[i]) continue; 

        used[i] = true;       
        path[step] = i;       
        dfs(step + 1);        
        used[i] = false;      
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