#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> lap;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        lap.push_back({a, b});
    }

    sort(lap.begin(), lap.end());
    for (int i = 0; i + 1 < n; i++)
    {
        if (lap[i].second > lap[i + 1].second)
        {
            cout << "Happy Alex\n";
            return;
        }
    }
    cout << "Poor Alex\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}