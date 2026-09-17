#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    string s;
    vector<int> a;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int tmp = s[i] - '0';
        if (tmp >= 1 && tmp <= 3)
            a.push_back(tmp);
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << a[i];
        if (i != (int)a.size() - 1)
            cout << '+';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}