#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, m;
    cin >> n >> m;
    ll ans = LLONG_MAX;
    vector<string> s(n);
    for (int i = 0; i < n;i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll diff = 0;
            for (int k = 0; k < m;k++)
            {
                diff += abs(s[i][k] - s[j][k]);
            }
            ans = min(ans, diff);
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