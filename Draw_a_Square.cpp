#include<bits/stdc++.h>
using namespace std;
void solve() 
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if (l == r && r == d && d == u)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}