#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    ll ans = 0;
    for (ll k = 2; k < n;k++)
    {
        ll i = 0, j = k - 1;
        while (i < j)
        {
            if(a[i]+a[j]>a[k])
            {
                ans += (j - i);
                j--;
            }
            else
            {
                i++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}