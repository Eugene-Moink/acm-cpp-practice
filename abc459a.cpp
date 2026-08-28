#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s = "HelloWorld";
    for (int i = 0; i < 10; i++)
    {
        if (i == n - 1)
            continue;

        cout << s[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}