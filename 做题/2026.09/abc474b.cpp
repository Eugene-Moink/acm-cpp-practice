#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int max_g = -1;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        int g = (p - 1) / 10;

        if (g < max_g)
        {
            cout << "No\n";
            return;
        }
        max_g = max(max_g, g);
    }
    cout << "Yes\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}