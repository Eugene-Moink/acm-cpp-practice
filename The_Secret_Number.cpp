#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> ans;
    ll mul = 10;
    for (ll i = 1; i <= 18;i++)
    {
        ll div = mul + 1;
        if(div>n)
        {
            break;
        }
        if(n%div==0)
        {
            ans.push_back(n / div);
        }
        mul *= 10;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size();
    if(ans.size()>0)
    {
        cout << " ";
    }

    for (ll i = 0; i < ans.size();i++)
    {
        cout << ans[i];
        if(i<ans.size()-1)
        {
            cout << " ";
        }
    }
    cout << endl;
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