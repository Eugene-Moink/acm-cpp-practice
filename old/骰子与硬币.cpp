#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n, k;
    cin >> n >> k;
    double ans = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        double result;
        if (i >= k)
        {
            result = 1.0;
        }
        else
        {
            int cur = i;
            int cnt = 0;
            while (cur < k)
            {
                cur *= 2;
                cnt++;
            }
            result = 1.0 / (1LL << cnt); 
        }
        ans += result;
    }
    double to = ans / n;
    cout << fixed << setprecision(12) << to << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}