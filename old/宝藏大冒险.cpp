#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const ll maxn= 1000005;

bool is_prime[maxn];
void build_prime_table()
{
    fill(is_prime, is_prime + maxn, true);
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i * i <= maxn;i++)
    {
        if(is_prime[i])
        {
            for (ll j = i * i; j <= maxn;j+=i)
            {
                is_prime[j] = 0;
            }
        }
    }
}

void moink()
{

    ll n;
    cin >> n;

    ll ans = 0;
    for (ll i = 0; i <= n;i++)
    {
        if(is_prime[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    build_prime_table();
    moink();
    return 0;
}