#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    cin >> s;
    if (s.size() > 9)
    {
        cout << "NO\n";
        return;
    }

    string cur = "";
    for (char c : s)
    {
        if (c != 'A')
            cur += c;
    }

    if (cur == "KIHBR")
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}