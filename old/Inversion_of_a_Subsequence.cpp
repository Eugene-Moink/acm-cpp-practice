#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll cnt_a_1 = 0, cnt_b_1 = 0;

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            cnt_a_1++;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] == 1)
        {
            cnt_b_1++;
        }
    }

    if (a == b)
    {
        cout << 0 << endl;
        return;
    }

    if (cnt_a_1 == 0)
    {
        cout << -1 << endl;
        return;
    }

    ll diff1 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] != b[i] && a[i] == 1)
        {
            diff1++;
        }
    }

    if (diff1 % 2 == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        if (cnt_a_1 == cnt_b_1)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}