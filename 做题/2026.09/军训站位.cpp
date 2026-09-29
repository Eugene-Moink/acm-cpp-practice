#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x = a[0];
    vector<int> rest(a.begin() + 1, a.end());

    bool ok = false;

    for (int i = 0; i < n; i++)
    {
        vector<int> b;
        for (int j = 0; j < i; j++)
            b.push_back(rest[j]);
        b.push_back(x);
        for (int j = i; j < n - 1; j++)
            b.push_back(rest[j]);

        bool sorted = true;
        for (int j = 1; j < n; j++)
        {
            if (b[j] < b[j - 1])
            {
                sorted = false;
                break;
            }
        }

        if (sorted)
        {
            ok = true;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}