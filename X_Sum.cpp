#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin >> a[i][j];
        }
    }

    map<int, ll> diag1, diag2;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            diag1[i - j] += a[i][j];      
            diag2[i + j] += a[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            ll sum = diag1[i - j] + diag2[i + j] - a[i][j]; 
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
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