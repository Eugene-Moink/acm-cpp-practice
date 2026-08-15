#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const int MAX = 1e5 + 5;
bool is_prime[MAX];
vector<ll> prime;
void init()
{
    fill(is_prime, is_prime + MAX, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < MAX;++i)
    {
        if(is_prime[i])
        {
            prime.push_back(i);
            for (ll j = 1LL * i * i; j < MAX;j+=i)
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
    vector<ll> a(n);
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n;i++)
    {
        if(a[i]==1)
        {
            cout << 2 << endl;
            return;
        }
    }

    unordered_set<ll> factors;
    for (int i = 0; i < n;i++)
    {
        ll x = a[i];
        for (ll p : prime)
        {
            if (p *p > x)
            {
                break;
            }
            if (x % p == 0)
            {
                factors.insert(p);
                while(x%p==0)
                {
                    x /= p;
                }
            }
        }
        if(x>1)
            factors.insert(x);
    }

    for(ll p : prime)
    {
        if(factors.find(p)==factors.end())
        {
            cout << p << endl;
            return;
        }
    }
}

int main()
{
    init();
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}