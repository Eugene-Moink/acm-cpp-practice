#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll n;
    cin>>n;
    ll ans = 1;

    ll first_num;
    cin >> first_num;
    bool last = first_num % 2;

    for(ll i=2;i<=n;i++)
    {
        ll num;
        cin >> num;
        bool current = num % 2;
        if(current!=last)
        {
            ans++;
            last = current;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}