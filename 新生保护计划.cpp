#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int num_add(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    while (n > 0)
    {
        n = n - num_add(n);
        cnt++;
    }
    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}