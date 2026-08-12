#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        string s;
        cin >> x >> s;
        a.push_back({x, s});
    }

    int idx = 0;
    for (int i = 0; i < m; i++)
    {
        int op, step;
        cin >> op >> step;
        if ((a[idx].first == 0 && op == 0) || (a[idx].first == 1 && op == 1))
        {
            idx = (idx - step + n) % n;
        }
        else
        {
            idx = (idx + step) % n;
        }
    }
    cout << a[idx].second << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}