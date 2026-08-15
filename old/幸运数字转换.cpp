#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s, t;
    cin >> s >> t;

    int cnt_4_7 = 0;
    int cnt_7_4 = 0;

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '4' && t[i] == '7')
        {
            cnt_4_7++;
        }
        else if (s[i] == '7' && t[i] == '4')
        {
            cnt_7_4++;
        }
    }

    cout << max(cnt_4_7, cnt_7_4) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}