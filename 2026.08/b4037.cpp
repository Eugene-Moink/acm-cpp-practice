#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int m;
    cin >> m;
    int mid = m / 2 + 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j == 1 || j == m || i == j)
            {
                cout << '+';
            }
            else
            {
                cout << '-';
            }
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}