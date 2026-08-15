#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> num(n);
    ll head = 0;
    for (ll i = 0; i < n;i++)
    {
        cin >> num[i];
    }

    for (ll i = 0; i < q;i++)
    {
        ll op;
        cin >> op;
        if (op == 1)
        {
            head = (head + 1) % n;
        }
        else
        {
            head=(head - 1 + n) % n;
        }
    }

    for (ll i = 0; i < n;i++)
    {
        cout << num[(head + i) % n];
        if (i < n - 1)
        {
            cout << " ";
        }
    }
}

int main()
{
    moink();
    return 0;
}