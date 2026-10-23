#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
#define pb push_back

const int MAXN = 1e6 + 5;
int stk[MAXN];
ull a[MAXN];
int top = 0;

void solve()
{
    ll n;
    cin >> n;

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ull x;
        cin >> x;
        a[i] = x;

        while (top > 0 && a[stk[top]] <= x)
        {
            ans ^= stk[top];
            top--;
        }

        stk[++top] = i;
        ans ^= i;

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}