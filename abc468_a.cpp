#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }

    int ans = 0;
    for (int i = 0; i + 2 < n; i++)
    {
        if (a[i] < a[i + 1] && a[i + 1] > a[i + 2])
        {
            ans++;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}