#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int max_keep = 0;
    for (int x : a)
    {
        int cnt = 0;
        for (int val : a)
        {
            if (val % x == 0)
                cnt++;
        }
        max_keep = max(max_keep, cnt);
    }
    cout << n - max_keep << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}