#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string a, b, c;
    cin >> a >> b >> c;
    if (a.back() == b.front() && b.back() == c.front())
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