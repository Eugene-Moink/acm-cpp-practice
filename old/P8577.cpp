#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1000005;
ll pref[MAXN];

void moink()
{
    int l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "";
    int i = 1;
    while ((int)s.size() < 1000000)
    {
        string num = to_string(i);
        for (int j = 0; j < i; ++j)
        {
            s += num;
        }
        ++i;
    }

    for (int i = 1; i <= 1000000; ++i)
    {
        pref[i] = pref[i - 1] + (s[i - 1] - '0');
    }

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}