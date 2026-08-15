#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int MAXN = 1000000;

vector<ll> fact(MAXN + 1), invfact(MAXN + 1);

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; i--) invfact[i-1] = invfact[i] * i % MOD;
}

ll C(int n, int k) {
    if (k < 0 || k > n || n < 0) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

void moink() {
    int n;
    string s;
    cin >> n >> s;

    int cnt00 = 0, cnt01 = 0, cnt10 = 0, cnt11 = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i+1] == '0') cnt00++;
        else if (s[i] == '0' && s[i+1] == '1') cnt01++;
        else if (s[i] == '1' && s[i+1] == '0') cnt10++;
        else cnt11++;
    }

    int total_0 = 0, total_1 = 0;
    for (char c : s) {
        if (c == '0') total_0++;
        else total_1++;
    }

    char first = s[0];
    int r = cnt01 + cnt10 + 1;

    int cnt0_run = 0, cnt1_run = 0;
    if (first == '0') {
        if (r % 2 == 1) {
            cnt0_run = (r + 1) / 2;
            cnt1_run = (r - 1) / 2;
        } else {
            cnt0_run = cnt1_run = r / 2;
        }
    } else { // first == '1'
        if (r % 2 == 1) {
            cnt1_run = (r + 1) / 2;
            cnt0_run = (r - 1) / 2;
        } else {
            cnt0_run = cnt1_run = r / 2;
        }
    }

    ll ways0 = 1, ways1 = 1;
    if (cnt0_run > 0) ways0 = C(total_0 - 1, cnt0_run - 1);
    else ways0 = (total_0 == 0 ? 1 : 0);

    if (cnt1_run > 0) ways1 = C(total_1 - 1, cnt1_run - 1);
    else ways1 = (total_1 == 0 ? 1 : 0);

    cout << ways0 * ways1 % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) moink();
    return 0;
}