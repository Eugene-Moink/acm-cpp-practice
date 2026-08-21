#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, m;
    cin >> n >> m;

    ll ini = 0, fin = 0;
    ll val;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> val;
            ini += (i * i + j * j) * val;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> val;
            fin += (i * i + j * j) * val;
        }
    }

    ll result = (ini - fin) / 2;
    cout << result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}