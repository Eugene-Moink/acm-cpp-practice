#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    int xiaofang = 0;
    int nailong = 0;

    for (char c : s1)
    {
        if (c == '0')
            xiaofang++;
        else
            nailong++;
    }

    for (char c : s2)
    {
        if (c == '0')
            xiaofang++;
        else
            nailong++;
    }

    cout << xiaofang << " " << nailong << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}