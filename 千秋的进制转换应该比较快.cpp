#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int val(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    if ('A' <= c && c <= 'F')
        return c - 'A' + 10;
    if ('a' <= c && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

void moink()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string bin = "";
    for (char c : s)
    {
        int v = val(c);
        for (int j = 3; j >= 0; j--)
        {
            bin += ((v >> j) & 1) ? '1' : '0';
        }
    }

    size_t start = bin.find('1');
    if (start == string::npos)
    {
        cout << "0" << '\n';
    }
    else
    {
        cout << bin.substr(start) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}