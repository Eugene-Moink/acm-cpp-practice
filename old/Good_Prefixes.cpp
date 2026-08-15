#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n;i++)
        {
            cin >> a[i];
        }

    ll cur = 0;
    set<ll> seen;
    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        cur += a[i];
        seen.insert(a[i]);
        if (cur % 2 == 0 &&seen.count(cur / 2))
        {
            ans++;
        }
    }
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