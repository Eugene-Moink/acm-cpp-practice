#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        reverse(a.begin(), a.begin() + k);
        for (int j = 0; j < k; j++)
            a[j] *= -1;
    }

    for (int x : a)
        cout << x << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}