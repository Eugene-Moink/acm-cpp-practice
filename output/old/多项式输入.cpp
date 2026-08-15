#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    bool is_zero = true;
    for (auto x : a)
    {
        if (x != 0) is_zero = false;
    }

    if (is_zero)
    {
        cout << "0" << endl;
        return;
    }

    bool is_first_term = true;
    for (ll i = 0; i <= n; i++)
    {
        ll coef = a[i];
        ll deg = n - i;

        if (coef == 0) continue;

        if (!is_first_term) 
        {  
            if (coef > 0) cout << "+";
            else cout << "-";
        } 
        else 
        {
            if (coef < 0) cout << "-";
            is_first_term = false; 
        }

        ll abs_coef = abs(coef);
        if (deg == 0)
        {
            cout << abs_coef;
        }
        else
        {
            if (abs_coef != 1)
            {
                cout << abs_coef;
            }
        }

        if (deg >= 1)
        {
            cout << 'x';
            if (deg > 1)
            {
                cout << '^' << deg;
            }
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}