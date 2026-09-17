#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    bool ok = 0;
    for (char c : s)
    {
        if (c == '"')
            ok = (!ok);

        if (!ok)
        {
            if (c == ',')
            {
                cout << '.';
                continue;
            }
        }
        cout << c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}