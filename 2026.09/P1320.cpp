#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string t = "";
    string s;
    int len = 0;
    while (cin >> s)
    {
        if (len == 0)
            len = s.size();
        t += s;
    }

    cout << len << ' ';
    char cur = '0';
    int cnt = 0;
    for (int i = 0; i <= (int)t.size(); i++)
    {
        char tmp = t[i];
        if (tmp == cur)
            cnt++;
        else
        {
            cur = tmp;
            cout << cnt << ' ';
            cnt = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}