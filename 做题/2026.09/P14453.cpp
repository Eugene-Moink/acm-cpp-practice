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
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        if (s >= a[i])
            s++;
        else
            s--;
    }
    ll max_val = s;

    sort(a.begin(), a.end(), greater<int>());
    s = 0;
    for (int i = 0; i < n; i++)
    {
        if (s >= a[i])
            s++;
        else
            s--;
    }
    ll min_val = s;

    cout << max_val << " " << min_val << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}