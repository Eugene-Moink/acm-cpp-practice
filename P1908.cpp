#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = 0;

void mSort(vector<ll> &a, int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mSort(a, l, mid);
    mSort(a, mid + 1, r);

    vector<ll> tmp;
    int i = l, j = mid + 1;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp.push_back(a[i++]);
        }
        else
        {
            ans += mid - i + 1;
            tmp.push_back(a[j++]);
        }
    }

    while (i <= mid)
        tmp.push_back(a[i++]);
    while (j <= r)
        tmp.push_back(a[j++]);

    for (int k = 0; k < (int)tmp.size(); k++)
    {
        a[l + k] = tmp[k];
    }
}

void solve()
{
    ans = 0;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    mSort(a, 0, n - 1);

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}