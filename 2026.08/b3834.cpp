#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(string s)
{
    int len = s.size();
    if (len < 6 || len > 12)
        return false;

    bool upper = false, lower = false, digit = false, special = false;

    for (char ch : s)
    {
        if (ch >= 'a' && ch <= 'z')
            lower = true;
        else if (ch >= 'A' && ch <= 'Z')
            upper = true;
        else if (ch >= '0' && ch <= '9')
            digit = true;
        else if (ch == '!' || ch == '@' || ch == '#' || ch == '$')
            special = true;
        else
            return false;
    }

    int typeCount = (upper ? 1 : 0) + (lower ? 1 : 0) + (digit ? 1 : 0);
    return (typeCount >= 2 && special);
}

void moink()
{
    string s;
    cin >> s;
    vector<string> parts;
    int start = 0;
    for (int i = 0; i <= s.size(); i++)
    {
        if (i == s.size() || s[i] == ',')
        {
            parts.push_back(s.substr(start, i - start));
            start = i + 1;
        }
    }

    for (auto &p : parts)
    {
        if (check(p))
        {
            cout << p << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}