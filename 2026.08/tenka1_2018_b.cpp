#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int a, b, k;
    cin >> a >> b >> k;

    int turn = 0;
    for (int i = 0; i < k; i++)
    {
        if (i % 2 == 0)
        {
            if (a % 2 == 1)
            {
                a--;
            }
            int give = a / 2;
            a -= give;
            b += give;
        }
        else
        {
            if (b % 2 == 1)
            {
                b--;
            }
            int give = b / 2;
            b -= give;
            a += give;
        }
    }

    cout << a << ' ' << b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}