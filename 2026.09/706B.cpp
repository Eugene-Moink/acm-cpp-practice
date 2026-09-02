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

    sort(a.begin(), a.end());
    int q;
    cin >> q;
    while (q--)
    {
        int cur;
        cin >> cur;

        int idx = upper_bound(a.begin(), a.end(), cur) - a.begin();
        cout << idx << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}