#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll k, x;
        cin >> k >> x;
        cout << k * x + 1 << "\n";
    }
    return 0;
}