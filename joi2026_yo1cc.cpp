#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());
    auto ans = a.end() - lower_bound(a.begin(), a.end(), h);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}