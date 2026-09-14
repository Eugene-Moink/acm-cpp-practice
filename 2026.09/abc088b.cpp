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
    int Alice = 0, Bob = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            Alice += a[i];
        else
            Bob += a[i];
    }
    cout << abs(Alice - Bob) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}