#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n;
    cin >> n;
    if (n < 10)
    {
        cout << n;
        return;
    }

    string s = to_string(n);
    ll a = pow(10, s.size() - 1) - 1;
    ll b = n - a;

    string a_str = to_string(a), b_str = to_string(b);
    ll ans = 0;
    for (char c : a_str)
    {
        ans += c - '0';
    }
    for (char c : b_str)
    {
        ans += c - '0';
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}