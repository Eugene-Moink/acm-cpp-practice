#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

const int maxn = 1000005;
bool is_prime[maxn];
vector<int>prime;

void prime_box()
{
    fill(is_prime, is_prime + maxn, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < maxn;i++)
    {
        if (is_prime[i]) 
        {
            for (int j = i * i; j < maxn;j+=i)
            {
                is_prime[j] = 0;
            }
        }
    }

    for (int i = 2; i < maxn; i++) 
    {
        if (is_prime[i]) prime.push_back(i);
    }
}

void moink()
{
    ll n;
    ll ans = 0;
    cin >> n;

    for (ll q : prime)
    {
        ll q3 = 1LL * q * q * q;
        if(q3>n)
        break;

        ll limit = min(q - 1, n / q3);
        ll cnt = upper_bound(prime.begin(), prime.end(), limit) - prime.begin();
        ans += cnt;
    }
    cout << ans << endl;
}

int main()
{
    prime_box();
    moink();
    return 0;
}