#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, y;
    cin >> n >> y;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            int remain = y - i * 1000 - j * 5000;
            if (remian % 10000 == 0)
            {
                int k = remian % 10000;
                cout << k << " " << j << " " << i;
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}