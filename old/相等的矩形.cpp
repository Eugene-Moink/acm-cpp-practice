#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<ll> a(4 * n);
    for (int i = 0; i < 4 * n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int l = 0, r = 4 * n - 1;
    ll area = a[l] * a[r];
    for (int i = 0; i < n; i++) 
    {
        if (a[l] != a[l + 1] || a[r] != a[r - 1])
        {
            cout << "No\n";
            return;
        }

        if(a[l] * a[r] != area)
        {
            cout << "No\n";
            return;
        }

        l += 2, r -= 2;
    }
    cout << "Yes\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}