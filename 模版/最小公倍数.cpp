#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const ll max_sqrt=31622;
vector<ll> prime;
bool is_prime[max_sqrt+1];
void init_primes()
{
    fill(is_prime, is_prime + max_sqrt + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i <= max_sqrt;++i)
    {
        if(is_prime[i])
        {
            prime.push_back(i);
            for (ll j = i * i; j <= max_sqrt;j+=i)
            {
                is_prime[j] = 0;
            }
        }
    }
}

unordered_map<ll, ll> max_exp;
void factorize(ll x)
{
    for(ll p : prime)
    {
        if (p *p > x)
        {
            break;
        }
        if (x % p == 0)
        {
            ll e = 0;
            while (x % p == 0)
            {
                x /= p;
                e++;
            }
            max_exp[p] = max(max_exp[p], e);
        }
    }
    if (x > 1)
    {
        max_exp[x] = max(max_exp[x], (ll)1);
    }
}

const ll mod = 998244353;
ll fast_pow(ll base,ll exp)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

void moink()
{
    init_primes();

    ll n;
    cin >> n;
    for (ll i = 0; i < n;++i)
    {
        ll a;
        cin >> a;
        factorize(a);
    }

    ll ans = 1;
    for (auto &kv : max_exp)
    {
        ll p = kv.first;
        ll e = kv.second;
        ans = (ans * fast_pow(p, e)) % mod;
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}