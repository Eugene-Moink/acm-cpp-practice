#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    if (n <= 3)
    {
        cout << "1\n";
        return;
    }

    ll d = (x2 - x1 + n) % n;
    d = min(d, n - d);
    cout << d + k << '\n';
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