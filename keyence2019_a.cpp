#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int a[10] = {0};
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    if (a[1] == 1 && a[9] == 1 && a[7] == 1 && a[4] == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}