#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll n, k;
ll a[25];
ll ans = 0;

const int MAX_SUM = 100000005; 
vector<bool> not_prime(MAX_SUM); 


void build_prime_table()
{
    not_prime[0] = not_prime[1] = true;
    for (ll i = 2; 1LL * i * i < MAX_SUM; i++)
    {
        if (!not_prime[i]) 
        {
            for (ll j = i * i; j < MAX_SUM; j += i)
            {
                not_prime[j] = true;
            }
        }
    }
}

bool isPrime(ll x)
{
    return !not_prime[x]; 
}

void dfs(ll step,ll cnt,ll sum)
{
    if (cnt > k)
        return;

    if (cnt + (n - step) < k)
        return;

    if(cnt==k)
    {
        if(isPrime(sum))
        {
            ans++;
            return;
        }
    }
    
    if (step == n) return;

    dfs(step + 1, cnt + 1, sum + a[step]);

    dfs(step + 1, cnt, sum);
}

void solve()
{
    build_prime_table();
    cin >> n >> k;
    for (ll i = 0; i < n;i++)
        cin >> a[i];

    dfs(0, 0, 0);
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}