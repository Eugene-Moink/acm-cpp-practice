#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    while (n--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        if (n1 + n2 + n3 >= 2)
            ans++;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}