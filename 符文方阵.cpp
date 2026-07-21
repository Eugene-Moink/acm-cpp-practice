#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> ans(m, vector<ll>(m));
    vector<vector<ll>> cur(m, vector<ll>(m));
    vector<vector<ll>> temp(m, vector<ll>(m, 0));

    for (ll i = 0; i < m; i++)
        for (ll j = 0; j < m; j++)
            cin >> ans[i][j];

    for (ll idx = 1; idx < n; idx++)
    {
        for (ll i = 0; i < m; i++)
            for (ll j = 0; j < m; j++)
                cin >> cur[i][j];

        for (ll i = 0; i < m; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                temp[i][j] = 0;
                for (ll k = 0; k < m; k++)
                {
                    temp[i][j] = (temp[i][j] + ans[i][k] * cur[k][j]) % 2;
                }
            }
        }

        ans = temp;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    moink();
    return 0;
}