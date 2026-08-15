#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    getline(cin, s);

    string res;
    bool sp = false;

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (sp && (res.empty() || res.back() != ' '))
                res += ' ';
            res += s[i];
            sp = false;
        }
        else if (s[i] == '.' || s[i] == '?' || s[i] == ',' || s[i] == '!')
        {
            if (!res.empty() && res.back() == ' ')
                res.pop_back();
            res += s[i];
            res += ' ';
            sp = true;
        }
        else if (s[i] == ' ')
        {
            sp = true;
        }
    }

    if (!res.empty() && res.back() == ' ')
        res.pop_back();

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}