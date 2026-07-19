#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, k, m;
    cin >> n >> k >> m;

    if (n < k || k > m)
    {
        cout << "NO" << endl;  
        return;
    }

    cout << "YES" << endl;

    for (ll i = 1; i <= n; ++i)
    {
        if (i % k == 0)
            cout << m - (k - 1);
        else
            cout << 1;

        if (i < n) cout << ' ';
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}