#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll x;
    cin >> x;
    ll low = x & 0xFFFF;
    ll new_high = low << 16;
    ll high = x >> 16;
    ll ans = new_high | high;
    cout << ans;
}

int main()
{
    moink();
    return 0;
}