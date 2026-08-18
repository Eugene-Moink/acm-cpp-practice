#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, q, C;
    cin >> n >> q >> C;
    string s;
    cin >> s;

    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int ans = 0;
        int best_diff = INT_MAX;

        for (int l = 1; l <= n - max(x, y) + 1; l++)
        {
            string a = s.substr(x - 1, l);
            string b = s.substr(y - 1, l);
            string doubled = a + a;

            if (doubled.find(b) != string::npos)
            {
                int diff = abs(l - z);
                if (diff < best_diff || (diff == best_diff && l < ans))
                {
                    best_diff = diff;
                    ans = l;
                }
            }
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}