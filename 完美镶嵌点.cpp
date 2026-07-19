#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, x;
    cin >> n >> x;
    bool inserted = false;
    bool first = true;

    for (ll i = 0; i < n; i++)
    {
        ll num;
        cin >> num;

        if (!inserted && num >= x)
        {
            if (!first) cout << " ";
            cout << x;
            first = false;
            inserted = true;
        }

        if (!first) cout << " ";
        cout << num;
        first = false;
    }

    if (!inserted)
    {
        if (!first) cout << " ";
        cout << x;
    }
    cout << endl;
}

int main()
{
    moink();
    return 0;
}