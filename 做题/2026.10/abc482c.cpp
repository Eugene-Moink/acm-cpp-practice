#include <bits/stdc++.h>
using namespace std;

int query_count(const vector<int> &v, int a, int b)
{
    auto l = lower_bound(v.begin(), v.end(), a);
    auto r = upper_bound(v.begin(), v.end(), b);
    return (int)(r - l);
}

void solve()
{
    int H, W, N, Q;
    cin >> H >> W >> N >> Q;

    vector<int> rows(N), cols(N);
    for (int i = 0; i < N; i++)
    {
        cin >> rows[i] >> cols[i];
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    while (Q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (a > b)
            swap(a, b);

        if (t == 1)
        {
            cout << query_count(rows, a, b) << '\n';
        }
        else
        {
            cout << query_count(cols, a, b) << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}