#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    ll ans = 1, cur = 1;
    for (size_t i = 1; i < a.size(); i++) 
    {
        if (a[i] == a[i - 1] + 1) 
        {
            cur++;
        } 
        else 
        {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    ans = max(ans, cur);
    cout << ans << endl;
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