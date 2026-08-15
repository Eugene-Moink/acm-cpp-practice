#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin>>n;
    vector<ll> odd,even;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        if(x%2==0)
            even.push_back(x);
        else
            odd.push_back(x);
    }
    if(odd.empty())
    {
        cout << 0 << endl;
        return;
    }

    ll ans = 0;
    for(ll x : even)
    {
        ans += x;
    }

    sort(odd.begin(), odd.end(), greater<ll>());
    int odd_half = (((int)odd.size() + 1) / 2);
    for (int i = 0; i < odd_half;i++)
    {
        ans += odd[i];
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        moink();
    }
    return 0;
}