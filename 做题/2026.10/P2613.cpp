#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 19260817;

ll mod_num(string s, ll p)
{
    ll res = 0;
    for (char c : s)
        res = (res * 10 + (c - '0')) % p;
    return res;
}

ll qpow(ll base, ll exp)
{
    ll res = 1;
    while (exp)
    {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

void solve()
{
    string a_str, b_str;
    cin >> a_str >> b_str;

    ll A = mod_num(a_str, MOD);
    ll B = mod_num(b_str, MOD);

    if (B == 0)
    {
        cout << "Angry!" << '\n';
        return;
    }

    ll inv_B = qpow(B, MOD - 2);
    ll ans = A * inv_B % MOD;

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}