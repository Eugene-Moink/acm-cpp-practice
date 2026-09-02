#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    cin >> n >> m;
    vector<ll> shair(n), neta(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> shair[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> neta[i];
    }

    sort(shair.begin(), shair.end());
    sort(neta.begin(), neta.end());
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m)
    {
        if (neta[j] <= 2 * shair[i])
        {
            ans++;
            i++, j++;
        }
        else if (neta[j] > 2 * shair[i])
        {
            i++;
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