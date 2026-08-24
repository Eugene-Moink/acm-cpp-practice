#include <bits/stdc++.h>
using namespace std;

int cmp(int x, int y)
{
    if (x > y)
        return 1;
    if (x == y)
        return 0;
    return -1;
}

void moink()
{
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int s_first = (i == 0 ? a1 : a2);
            int s_second = (i == 0 ? a2 : a1);
            int sl_first = (j == 0 ? b1 : b2);
            int sl_second = (j == 0 ? b2 : b1);
            int res = cmp(s_first, sl_first) + cmp(s_second, sl_second);
            if (res > 0)
                ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        moink();
    return 0;
}