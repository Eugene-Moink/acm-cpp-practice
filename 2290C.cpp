#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    int k = n;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            cnt++;
        }
        else
        {
            if (cnt > 2)
                k -= (cnt - 2);
            cnt = 1;
        }
    }
    if (cnt > 2)
        k -= (cnt - 2);

    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            even.pb(a[i]);
        else
            odd.pb(a[i]);
    }
    reverse(odd.begin(), odd.end());

    cout << k << '\n';
    for (int x : even)
        cout << x << ' ';
    for (int x : odd)
        cout << x << ' ';
    cout << '\n';
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