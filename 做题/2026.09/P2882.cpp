#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<char> a;
int simulate(int k)
{
    vector<int> diff(n + 2, 0);
    int cur = 0, ops = 0;

    for (int i = 1; i <= n; ++i)
    {
        cur += diff[i];
        char c = a[i];
        if (cur % 2 == 1)
            c = (c == 'B') ? 'F' : 'B';

        if (c == 'B')
        {
            if (i + k - 1 > n)
                return -1;

            diff[i]++, diff[i + k]--;
            cur++, ops++;
        }
    }
    return ops;
}

void solve()
{
    cin >> n;
    a.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int best_k = 1, best_ops = INT_MAX;
    for (int k = 1; k <= n; k++)
    {
        int ops = simulate(k);
        if (ops != -1)
        {
            if (ops < best_ops || (ops == best_ops && k < best_k))
            {
                best_ops = ops;
                best_k = k;
            }
        }
    }
    cout << best_k << " " << best_ops << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}