#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    set<ll> a;
    for (ll i = 0; i < n;i++)
    {
        ll x;
        cin >> x;
        a.insert(x);
    }
    cout << a.size() << endl;
}

int main()
{
    moink();
    return 0;
}