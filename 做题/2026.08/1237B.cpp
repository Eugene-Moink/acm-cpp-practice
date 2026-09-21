#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }

    vector<bool> exit(n + 1, 0);
    int ptr = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x = b[i];
        exit[x] = 1;
        if (x != a[ptr])
        {
            ans++;
        }

        else
        {
            while (ptr < n && exit[a[ptr]])
            {
                ptr++;
            }
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}