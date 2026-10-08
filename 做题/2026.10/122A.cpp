#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{

    int n;
    cin >> n;

    int lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    int len = sizeof(lucky) / sizeof(lucky[0]);

    for (int i = 0; i < len; i++)
    {
        if (n % lucky[i] == 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}