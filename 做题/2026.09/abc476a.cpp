#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;

    if (s.back() == 'e')
        cout << s + "r" << '\n';
    else
        cout << s + "er" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}