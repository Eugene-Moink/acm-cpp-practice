#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    cin >> s;
    string t = "keyence";
    for (int i = 0; i <= 7; i++)
    {
        string s_front = s.substr(0, i);
        string s_back = s.substr(s.size() - (7 - i), 7 - i);
        if (s_front + s_back == t)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}