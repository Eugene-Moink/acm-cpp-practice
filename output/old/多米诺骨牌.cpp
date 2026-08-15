#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;

void moink()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for (int a = 0; a <= 1; a++)
    {
        for (int b = 0; b <= 1; b++)
        {
            bool ok = true;
            for (int i = 0; i < n; i++)
            {
                char need;
                int pos = i % 4;
                if (pos == 0) need = '0' + a;
                else if (pos == 1) need = '0' + b;
                else if (pos == 2) need = '0' + (1 - a);
                else need = '0' + (1 - b);

                if (s[i] != '?' && s[i] != need)
                {
                    ok = false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }

    cout << ans % MOD << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) moink();
    return 0;
}