#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }

    cout << n * sum << endl;
}

int main()
{
    moink();
    return 0;
}