#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    string s;
    cin >> s;

    int cnt = 0;
    for (char c : s)
    {
        if (c == 'o')
            cnt++;
    }

    if (cnt % 2 == 1)
        cout << "odd\n";
    else
        cout << "even\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}