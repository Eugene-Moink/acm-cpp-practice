#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cur = 0;
    int min_cur = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cur += x;
        min_cur = min(min_cur, cur);
    }

    cout << 1 - min_cur << '\n';

    return 0;
}