#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> sum(n + 1, vector<ll>(m + 1, 0));

    for (ll i = 1; i <= n;i++)
    {
        for (ll j = 1; j <= m;j++)
        {
            cin >> a[i][j];
        }
    }

    for (ll i = 1; i <= n;i++)
    {
        for (ll j = 1; j <= m;j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    }

    for (ll i = 1; i <= n;i++)
    {
        for (ll j = 1; j <= m;j++)
        {
            ll g = sum[i][j] / (i * j);
            cout << g << " ";
        }
        cout << endl;
    }
}

int main()
{
    moink();
    return 0;
}