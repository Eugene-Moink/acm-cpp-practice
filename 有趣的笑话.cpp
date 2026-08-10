#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s, t;
    cin >> s >> t;
    string temp = s + t;
    vector<int> a(26, 0);
    for (char c : temp)
    {
        a[c - 'A']++;
    }

    string to;
    cin >> to;
    for (char c : to)
    {
        a[c - 'A']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}