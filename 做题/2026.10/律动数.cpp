#include <bits/stdc++.h>
using namespace std;

bool check(int num)
{
    string s = to_string(num);
    for (int i = 0; i < s.size(); i++)
    {
        int digit = s[i] - '0';
        if (i % 2 == 0)
        {
            if (digit % 2 == 0)
                return false;
        }
        else
        {
            if (digit % 2 != 0)
                return false;
        }
    }
    return true;
}

void solve()
{
    int x, y;
    cin >> x >> y;

    bool first = true;
    for (int i = x; i <= y; i++)
    {
        if (check(i))
        {
            if (!first)
                cout << " ";
            cout << i;
            first = false;
        }
    }

    if (first)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}