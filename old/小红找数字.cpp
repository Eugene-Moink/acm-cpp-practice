#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    cin >> s;
    for (char c : s)
    {
        if (c >= '0' &&c <= '9')
        {
            cout << c;
            return;
        }
    }
    cout << -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}