#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    ll sum_a_mod = 0, sum_b_mod = 0;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum_a_mod = (sum_a_mod + x) & 1;
    }

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum_b_mod = (sum_b_mod + x) & 1;
    }

    if (sum_a_mod == 1 && sum_b_mod == 1)
    {
        cout << "odd" << endl;
    }
    else
    {
        cout << "even" << endl;
    }
}

int main()
{
    moink();
    return 0;
}