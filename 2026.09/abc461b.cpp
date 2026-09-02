#include <bits/stdc++.h>
using namespace std;

void moink()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    bool ok = true;
    for (int i = 1; i <= n; ++i)
    {
        if (b[a[i]] != i)
        {
            ok = false;
            break;
        }
    }

    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}