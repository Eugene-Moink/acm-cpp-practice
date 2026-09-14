#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int cur = 0, best = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x = (a[i] == 0) ? 1 : -1;
        cur = max(cur + x, x);
        best = max(cur, best);
    }

    int cnt1 = count(a.begin(), a.end(), 1);
    cout << best + cnt1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}