#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    ll cnt[101] = {0};

    for (ll i = 0; i < n;i++)
    {
        ll x;
        cin >> x;
        cnt[x]++;
    }

    ll find;
    cin >> find;
    ll high = 0;
    for (ll i=find + 1; i <= 100; i++)
    {
        high += cnt[i];
    }

    cout << high + 1 << endl;
}

int main()
{
    moink();
    return 0;
}