#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n;
    cin >> n;

    int ans = 0;

    int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    auto add = [&](int x)
    {
        if (x == 0)
            return 6;
        int sum = 0;
        while (x > 0)
        {
            sum += cost[x % 10];
            x /= 10;
        }
        return sum;
    };

    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            int k = i + j;
            if (add(i) + add(j) + add(k) + 4 == n)
                ans++;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}