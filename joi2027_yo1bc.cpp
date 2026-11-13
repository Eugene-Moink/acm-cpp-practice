#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    int cnt = 0;

    while (n--)
    {
        int h;
        string s;
        cin >> h >> s;
        if (s == "No")
            continue;
        else
        {
            if (h >= l && h <= r)
                cnt++;
        }
    }
    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}