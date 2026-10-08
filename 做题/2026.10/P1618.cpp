#include <bits/stdc++.h>
using namespace std;

bool seen[10];

void solve()
{
    int a, b, c;
    bool found = false;
    cin >> a >> b >> c;

    if (a == 0)
    {
        cout << "No!!!";
        return;
    }

    for (int k = 1; c * k <= 999; k++)
    {
        int x = a * k;
        int y = b * k;
        int z = c * k;

        if (x < 100)
            continue;

        string s = to_string(x) + to_string(y) + to_string(z);

        for (int i = 0; i <= 9; i++)
            seen[i] = false;

        for (char ch : s)
            seen[ch - '0'] = true;

        bool ok = true;
        for (int i = 1; i <= 9; i++)
        {
            if (!seen[i])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            found = true;
            cout << x << ' ' << y << ' ' << z << '\n';
        }
    }

    if (!found)
        cout << "No!!!" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}