#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n;
    cin >> n;
    cout << __builtin_popcountll(n) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}