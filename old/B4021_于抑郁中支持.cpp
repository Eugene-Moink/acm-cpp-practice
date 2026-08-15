#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve() 
{
    ll n, t;
    cin >> n >> t;
    ll mod = 1;
    for (ll i = 0; i < t;i++)
    {
        mod *= 10;
    }

    unordered_set<ll> events;
    for (ll i = 0; i < n;i++)
    {
        ll val;
        cin >> val;
        events.insert(val % mod);
    }

    cout << events.size() << endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve(); 
    return 0;
}