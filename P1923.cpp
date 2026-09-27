#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int qSelect(vector<int> &a, int l, int r, int k)
{
    if (l == r)
        return a[l];

    int idx = (l + r) / 2;
    int pivot = a[idx];
    swap(a[idx], a[l]);

    int i = l, j = r;
    while (i < j)
    {
        while (i < j && a[j] >= pivot)
            j--;
        while (i < j && a[i] <= pivot)
            i++;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[i], a[l]);

    if (i == k)
        return a[i];
    else if (i > k)
        return qSelect(a, l, i - 1, k);
    else
        return qSelect(a, i + 1, r, k);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int ans = qSelect(a, 0, n - 1, k);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}