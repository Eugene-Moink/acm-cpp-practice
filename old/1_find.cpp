#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const ll mod=998244353;
const int maxn = 1000005;
ll pow10[maxn];
void moink()
{
    int n;
    cin >> n;
    
    if(n==0)
    {
        cout << 0 << endl;
        return;
    }

    ll ans = (ll)n * pow10[n - 1] % mod;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pow10[0] = 1;
    for (ll i = 1; i < maxn;i++)
    {
        pow10[i] = pow10[i - 1] * 10 % mod;
    }

    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}