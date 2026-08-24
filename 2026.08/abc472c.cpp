#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> eat(n);
    for (int i = 0; i < n; ++i)
        cin >> eat[i];

    queue<pair<int, ll>> q;
    ll cur = 0;

    for (int i = 1; i <= n; ++i)
    {
        while (!q.empty() && q.front().first < i - m + 1)
        {
            cur -= q.front().second;
            q.pop();
        }

        if (cur + eat[i - 1] <= k)
        {
            cout << "Yes\n";
            cur += eat[i - 1];
            q.push({i, eat[i - 1]});
        }
        else
        {
            cout << "No\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}