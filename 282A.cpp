#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, x = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.find("++") != string::npos)
            x++;
        else
            x--;
    }

    cout << x << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}