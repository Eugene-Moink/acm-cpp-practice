#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, k;
    cin >> n >> k;

    int rem1 = n - (k - 1);
    if (rem1 > 0 &&(rem1 & 1))
    {
        cout << "Yes\n";
        for (int i = 1; i < k; ++i)
        {
            cout << 1 << " ";
        }
        cout << rem1 << '\n';
        return;
    }

    int rem2 = n - 2 * (k - 1);
    if (rem2 > 0 &&(rem2 % 2 == 0))
    {
        cout << "Yes\n";
        for (int i = 1; i < k; ++i)
        {
            cout << 2 << " ";
        }
        cout << rem2 << '\n';
        return;
    }
    cout << "No\n";
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