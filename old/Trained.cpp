#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n;i++)
    {
        cin >> a[i];
    }

    vector<bool> visit(n + 1, 0);
    ll cur = 1;
    ll ans = 0;
    while(1)
    {
        if (cur == 2)
        {
            cout << ans << endl;
            return;
        }
        if (visit[cur] == 1)
        {
            cout << "-1" << endl;
            return;
        }
        visit[cur] = 1;
        cur = a[cur];
        ans++;
    }
}

int main()
{
    moink();
    return 0;
}
