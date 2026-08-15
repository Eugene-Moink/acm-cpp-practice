#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    int cur = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        int target = -1;
        int w, h;
        cin >> w >> h;
        if (w <= cur)
        {
            target = max(target, w);
        }
        if (h <= cur)
        {
            target = max(target, h);
        }

        if (target == -1)
        {
            cout << "NO\n";
            return;
        }

        cur = target;
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}