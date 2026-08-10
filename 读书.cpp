#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n, m;
    cin >> n >> m;

    if (m % 10 == 0) 
    {   
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;
    vector<int> cycle;
    int cur = m % 10;
    while(1)
    {
        cycle.push_back(cur);
        cur = (cur + m) % 10;
        if(cur == m % 10)
            break;
    }

    ll cnt = n / m;
    ll full = cnt / cycle.size(), rem = cnt % cycle.size();
    ll sum = 0;
    for(int x : cycle)
        sum += x;

    ll rem_sum = 0;
    for (int i = 0; i < rem; i++)
        rem_sum += cycle[i];

    ans = sum * full + rem_sum;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}