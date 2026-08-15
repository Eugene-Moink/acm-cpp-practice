#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s)
    {
        if (c == '4' || c == '7')
            cnt++;
    }
    cout << ((cnt == 4 || cnt == 7) ? "YES" : "NO") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}