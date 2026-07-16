#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll layer = min( min(i, n - 1 - i), min(j, n - 1 - j) );

            if (layer % 2 == 0) cout << "#";
            else cout << ".";
        }
        cout << endl; 
    }
}

int main()
{
    solve();
    return 0;
}