#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt_odd = 0, cnt_even = 0;
    for (int &x : a)
    {
        cin >> x;
        if (x % 2 == 1)
            cnt_odd++;
        else
            cnt_even++;
    }

    if (cnt_odd == 1)
    {
        int cnt = 0;
        for (int x : a)
        {
            cnt++;
            if (x % 2 == 1)
            {
                cout << cnt;
                return;
            }
        }
    }

    if (cnt_even == 1)
    {
        int cnt = 0;
        for (int x : a)
        {
            cnt++;
            if (x % 2 == 0)
            {
                cout << cnt;
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}