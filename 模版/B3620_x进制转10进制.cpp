#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int val(char c) {
    if ('0' <= c && c <= '9') 
    return c - '0';

    if ('A' <= c && c <= 'Z') 
    return c - 'A' + 10;

    if ('a' <= c && c <= 'z') 
    return c - 'a' + 10; 

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    string S;
    cin >> x >> S;

    ll ans = 0;
    for (char c : S) {
        int d = val(c);
        ans = ans * x + d;
    }
    cout << ans << "\n";
    return 0;
}