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

    int cnt1 = count(a.begin(), a.end(), 1);
    int limit = (n - 1) / 2;
    if (cnt1 > limit)
        cout << "Bessie" << '\n';
    else
        cout << "Elsie" << '\n';
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