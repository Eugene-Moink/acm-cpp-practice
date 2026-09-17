#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int ansboy = 0, ansgirl = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (i + 2 < n && (s[i] == 'b' || s[i + 1] == 'o' || s[i + 2] == 'y'))
            ansboy++;
        if (i + 3 < n && (s[i] == 'g' || s[i + 1] == 'i' || s[i + 2] == 'r' || s[i + 3] == 'l'))
            ansgirl++;
    }

    cout << ansboy << '\n'
         << ansgirl << '\n';
    return 0;
}