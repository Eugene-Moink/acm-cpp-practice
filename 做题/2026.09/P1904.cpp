#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<array<int, 3>> bs;
    vector<int> xs;

    int L, H, R;
    while (cin >> L >> H >> R)
    {
        bs.push_back({L, H, R});
        xs.push_back(L);
        xs.push_back(R);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    int last = 0;
    bool first = true;

    for (int i = 0; i + 1 < (int)xs.size(); i++)
    {
        int maxH = 0;
        for (auto &b : bs)
        {
            if (b[0] <= xs[i] && xs[i + 1] <= b[2])
            {
                maxH = max(maxH, b[1]);
            }
        }

        if (maxH != last)
        {
            if (!first)
                cout << ' ';
            cout << xs[i] << ' ' << maxH;
            first = false;
            last = maxH;
        }
    }

    if (last != 0)
    {
        if (!first)
            cout << ' ';
        cout << xs.back() << " 0";
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}