#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int m, s;
    cin >> m >> s;

    if ((m > 1 && s == 0) || s > 9 * m)
    {
        cout << "-1 -1" << '\n';
        return;
    }

    if (m == 1 && s == 0)
    {
        cout << "0 0" << '\n';
        return;
    }

    string min_num(m, '0');
    int cur_s = s - 1;
    for (int i = m - 1; i >= 1; --i)
    {
        if (cur_s > 9)
        {
            min_num[i] = '9';
            cur_s -= 9;
        }
        else
        {
            min_num[i] = '0' + cur_s;
            cur_s = 0;
            break;
        }
    }
    min_num[0] = cur_s + '1';

    string max_num(m, '0');
    cur_s = s;
    for (int i = 0; i < m; i++)
    {
        if (cur_s > 9)
        {
            max_num[i] = '9';
            cur_s -= 9;
        }
        else
        {
            max_num[i] = '0' + cur_s;
            cur_s = 0;
            break;
        }
    }

    cout << min_num << " " << max_num << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}