#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for (int &x : b)
        cin >> x;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        ll sum = 0;
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            sum += b[j] * tmp;
        }
        if (sum + c > 0)
            cnt++;
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