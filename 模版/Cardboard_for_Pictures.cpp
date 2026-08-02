#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
    }

    ll l = 0, r = 2e9;
    while(l<r)
    {
        ll mid = (l + r + 1) / 2;

        ll sum = 0;
        bool ok = 1;
        for (int i = 0; i < n;i++)
        {
            ll need = a[i] + 2 * mid;
            sum += need * need;
            if(sum>c)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}               