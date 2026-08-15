#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    int sum = INT_MAX;
    for (int i = 1; i <= 100; ++i)
    {
        int ans = 0;
        for (int j = 1; j <= n;j++)
        {
            int tmp = a[j] - i;
            ans += tmp * tmp;
        }
        sum = min(ans, sum);
    }
    cout << sum << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}