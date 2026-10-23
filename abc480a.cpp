#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    vector<string> grid = {s1, s2};

    int rA = -1, cA = -1;
    int rD = -1, cD = -1;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (grid[i][j] == 'A')
            {
                rA = i;
                cA = j;
            }
            if (grid[i][j] == 'D')
            {
                rD = i;
                cD = j;
            }
        }
    }

    if (abs(rA - rD) + abs(cA - cD) == 1)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}