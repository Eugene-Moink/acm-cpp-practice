#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;
vector<int> cur;
vector<int> suffix_gcd;

int gcd_int(int a, int b)
{
    while (b)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void dfs(int pos, ll rem)
{
    if (pos == N)
    {
        if (rem % N == 0)
        {
            cur[pos] = rem / N;
            for (int i = 1; i <= N; ++i)
            {
                cout << cur[i] << (i == N ? '\n' : ' ');
            }
        }
        return;
    }

    int g = suffix_gcd[pos + 1];
    for (int a = 0; 1LL * pos * a <= rem; ++a)
    {
        ll new_rem = rem - 1LL * pos * a;
        if (new_rem % g != 0)
            continue;
        cur[pos] = a;
        dfs(pos + 1, new_rem);
    }
}

void solve()
{
    cin >> N >> K;
    cur.assign(N + 1, 0);
    suffix_gcd.assign(N + 2, 0);

    suffix_gcd[N] = N;
    for (int i = N - 1; i >= 1; --i)
    {
        suffix_gcd[i] = gcd_int(i, suffix_gcd[i + 1]);
    }

    dfs(1, K);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}