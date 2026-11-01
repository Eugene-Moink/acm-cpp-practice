#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct player
{
    string id;
    int solved;
    ll penalty;
    int rank;
};

bool cmp(const player &a, const player &b)
{
    if (a.solved != b.solved)
        return a.solved > b.solved;
    if (a.penalty != b.penalty)
        return a.penalty < b.penalty;
    return a.id < b.id;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<player> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].id;
        int pass = 0;
        ll sum = 0;
        for (int j = 0; j < m; j++)
        {
            ll tmp;
            cin >> tmp;
            if (tmp > 0)
                pass++;
            sum += tmp;
        }
        a[i].solved = pass;
        a[i].penalty = sum;
    }

    sort(a.begin(), a.end(), cmp);

    if (a[0].solved == 0)
    {
        for (int i = 0; i < n; i++)
            a[i].rank = 1;
    }
    else
    {
        a[0].rank = 1;
        int last_ac_rank = 1;

        for (int i = 1; i < n; i++)
        {
            if (a[i].solved == 0)
            {
                a[i].rank = last_ac_rank + 1;
            }
            else if (a[i].solved == a[i - 1].solved && a[i].penalty == a[i - 1].penalty)
            {
                a[i].rank = a[i - 1].rank;
                last_ac_rank = a[i].rank;
            }
            else
            {
                a[i].rank = i + 1;
                last_ac_rank = a[i].rank;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i].rank << ' ' << a[i].id << ' '
             << a[i].solved << ' ' << a[i].penalty << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}