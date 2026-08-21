#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int Q;
    ll V;
    cin >> Q >> V;

    priority_queue<ll> pq;

    while (Q--)
    {
        int type;
        ll t;
        cin >> type >> t;
        if (type == 1)
        {
            ll W;
            cin >> W;
            pq.push(W - t);
        }
        else
        {
            if (pq.empty())
            {
                cout << "-1\n";
            }
            else
            {
                ll key = pq.top();
                pq.pop();
                ll now = key + t;
                if (now > V)
                    now = V;
                cout << now << '\n';
            }
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