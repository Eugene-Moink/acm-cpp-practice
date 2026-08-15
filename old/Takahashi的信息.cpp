#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int c[3][3];
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            cin >> c[i][j];
        }
    }

    int a[3], b[3];
    a[0] = 0;
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];

    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];

    bool ok = true;
    for (int i = 0; i < 3 && ok; i++)
        for (int j = 0; j < 3; j++)
            if (c[i][j] != a[i] + b[j])
                ok = false;

    cout << (ok ? "Yes" : "No") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}