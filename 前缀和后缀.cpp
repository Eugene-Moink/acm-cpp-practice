#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    int len = 0;
    for (int i = n; i >= 0; i--)
    {
        if (s.substr(n - i, i) == t.substr(0, i))
        {
            len = i;
            break;
        }
    }
    cout << n * 2 - len << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}