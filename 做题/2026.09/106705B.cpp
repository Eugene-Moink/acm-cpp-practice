#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef tuple<ll, int, ll> Event;

void solve()
{
    int n, q;
    cin >> n >> q;

    ll sub = 0;
    int cnt = 0;
    vector<ll> val(n);
    vector<int> light(n);
    for (int &x : light)
        cin >> x;

    for (int i = 0; i < n; i++)
        val[i] = light[i];

    priority_queue<Event, vector<Event>, greater<Event>> pq;
    for (int i = 0; i < n; i++)
    {
        if (val[i] > 0)
        {
            cnt++;
            pq.push({light[i], i, light[i]});
        }
    }

    while (q--)
    {
        int x;
        ll v;
        cin >> x >> v;

        sub++;
        while (!pq.empty())
        {
            auto [e, idx, ver] = pq.top();
            if (ver != val[idx])
            {
                pq.pop();
                continue;
            }
            if (e <= sub)
            {
                pq.pop();
                cnt--;
            }
            else
            {
                break;
            }
        }

        if (x != 0)
        {
            x--;
            ll newVal = max(val[x], v + sub);
            if (newVal != val[x])
            {
                if (val[x] <= sub && newVal > sub)
                    cnt++;

                val[x] = newVal;
                if (newVal > sub)
                    pq.push({newVal, x, newVal});
            }
        }

        cout << cnt << '\n';
    }
    for (int i = 0; i < n; i++)
        cout << max(0LL, val[i] - sub) << " \n"[i == n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}