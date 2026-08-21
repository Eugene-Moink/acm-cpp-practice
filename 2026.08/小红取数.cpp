#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            c2++;
        else
            c1++;
    }
    cout << (c1 > 0 ? c1 : -1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}