#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    int val_min = INT_MAX, val_max = -1;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        val_max = max(val_max, x);
        val_min = min(val_min, x);
    }
    cout << val_max - val_min << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}