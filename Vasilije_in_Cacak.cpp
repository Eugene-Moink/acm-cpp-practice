#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, k, x;
    cin >> n >> k >> x;
    int min_s = k * (k + 1) / 2;
    int max_s = k * (2 * n - k + 1) / 2;
    if (x >= min_s &&x <= max_s)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}