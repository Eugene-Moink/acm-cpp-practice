#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll n, x1, y1, x2, y2;
    string s;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    cin >> s;

    ll dx = x1 - x2;
    ll dy = y1 - y2;

    int cx = 0, cy = 0;
    for (char c : s)
    {
        if (c == 'L' || c == 'R')
            cx++;
        else
            cy++;
    }

    ll ndx = abs(dx), ndy = abs(dy);
    ll ans = ndx + ndy + cx + cy;

    string t = "";
    for (char c : s)
    {
        bool give_A;
        if (c == 'L' || c == 'R')
        {
            if (dx >= 0)
            {
                if (c == 'R')
                    give_A = true;
                else
                    give_A = false;
            }
            else
            {
                if (c == 'L')
                    give_A = true;
                else
                    give_A = false;
            }
        }
        else
        {
            if (dy >= 0)
            {
                if (c == 'U')
                    give_A = true;
                else
                    give_A = false;
            }
            else
            {
                if (c == 'D')
                    give_A = true;
                else
                    give_A = false;
            }
        }

        if (give_A)
            t += 'A';
        else
            t += 'B';
    }

    cout << ans << '\n'
         << t << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}