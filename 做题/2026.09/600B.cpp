#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &val : a)
        cin >> val;
    for (int &val : b)
        cin >> val;

    sort(a.begin(), a.end());
    for (int &x : b)
    {
        int pos = upper_bound(a.begin(), a.end(), x) - a.begin();
        cout << pos << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}