#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll w;
    cin >> w;
    vector<ll> ans;
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(4);

    ll max_cover = 7;
    while(max_cover<w)
    {
        ll nxt = max_cover + 1;
        ans.push_back(nxt);
        max_cover += nxt;
    }
    cout << ans.size() << endl;
    for (ll x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    moink();
    return 0;
}