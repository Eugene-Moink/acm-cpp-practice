#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }

    int cnt1 = 0, cnt4_2 = 0, cnt4_0 = 0;

    for (int x : a)
    {
        if (x % 2 == 1)
            cnt1++;
        else if (x % 4 == 2)
            cnt4_2++;
        else
            cnt4_0++;
    }

    cout << max({cnt1, cnt4_2, cnt4_0}) << '\n';
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