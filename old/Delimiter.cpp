#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    vector<ll> num;
    while(1)
    {
        ll n;
        cin >> n;
        num.push_back(n);
        if(n==0)
            break;
    }

    reverse(num.begin(), num.end());

    for (ll i = 0; i < num.size();i++)
    {
        cout << num[i] << endl;
    }
}       

int main()
{
    solve();
    return 0;
}