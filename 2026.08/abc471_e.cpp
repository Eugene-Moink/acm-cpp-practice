#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int MAXN = 1000000;

ll fact[MAXN + 5], invfact[MAXN + 5];

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init()
{
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MAXN] = qpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; --i)
    {
        invfact[i - 1] = invfact[i] * i % MOD;
    }
}

ll C(int n, int k)
{
    if (k < 0 || k > n || n < 0)
        return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

void moink()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll S = 0, S2 = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ll x = a[i] % MOD;
        S = (S + x) % MOD;
        S2 = (S2 + x * x) % MOD;
    }

    ll c1 = C(n - 1, k - 1);
    ll c2 = C(n - 2, k - 2);
    ll ans = (c1 * S2 % MOD + c2 * ((S * S % MOD - S2 + MOD) % MOD)) % MOD;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    moink();

    return 0;
}