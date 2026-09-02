#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, s, x;
    cin >> n >> s >> x;

    ll cur = 0;
    int cnt = 1;
    while (1)
    {
        int v;
        cin >> v;
        if (v == 0)
            cur += x;
        else if (v == -1)
        {
            cur += 0;
        }
        else if (v >= 1)
        {
            cur += (x - v);
        }

        if (cur >= s)
        {
            cout << cnt << '\n';
            return;
        }

        if (cnt == n && cur < s)
        {
            cout << -1 << '\n';
            return;
        }

        cnt++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}