#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        unordered_map<int, int> cnt;
        for (int i = l - 1; i < r; i++)
        {
            cnt[a[i]]++;
        }
        int max_cnt = -1;
        for (auto &p : cnt)
        {
            max_cnt = max(max_cnt, p.second);
        }
        cout << max_cnt << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}