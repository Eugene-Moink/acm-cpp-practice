#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    cout << (isPrime(n) ? "Yes" : "No") << '\n';
    return 0;
}