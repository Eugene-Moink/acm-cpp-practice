#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
const ll mod = 1e9 + 7;

void moink()
{
    ll n, m;
    cin >> n >> m;
    if(abs(n-m)>1)
    {
        cout << "0" << endl;
        return;
    }

    ll n_fact = 1;
    ll m_fact = 1;
    for (ll i = 1; i <= n;i++)
    {
        n_fact = (n_fact * i) % mod;
    }
    for (ll i = 1; i <= m;i++)
    {
        m_fact = (m_fact * i) % mod;
    }
    ll ans = (n_fact * m_fact) % mod;

    if (n == m)
    {
        ans = (ans * 2) % mod;
        
    }

    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}