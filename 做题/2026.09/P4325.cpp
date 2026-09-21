#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    map<int, int> cnt;
    for (int i = 1; i <= 10; i++)
    {
        int n;
        cin >> n;
        cnt[n % 42]++;
    }
    cout << cnt.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}