#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int cntR = 0, cntF = 0, cntJunk = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && t[i] == 'B')
            cntR++;
        else if (s[i] == '1' && t[i] == 'R')
            cntF++;
        else
            cntJunk++;
    }

    int scoreR = 0, scoreF = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (cntR > 0)
            {
                cntR--;
                scoreR++;
            }
            else if (cntF > 0)
            {
                cntF--;
            }
            else
            {
                cntJunk--;
            }
        }
        else
        {
            if (cntF > 0)
            {
                cntF--;
                scoreF++;
            }
            else if (cntR > 0)
            {
                cntR--;
            }
            else
            {
                cntJunk--;
            }
        }
    }

    if (scoreR > scoreF)
        cout << "Rainbow" << '\n';
    else if (scoreF > scoreR)
        cout << "Flower" << '\n';
    else
        cout << "Draw" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}