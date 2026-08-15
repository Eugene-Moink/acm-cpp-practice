#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<ll> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll a = v[0], b = v[1], c = v[2];
    if (c > a + b) cout << b << '\n';
    else cout << c - a << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}