#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3000005;
int a[MAXN], ans[MAXN];
int stk[MAXN];
int top = 0;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = n; i >= 1; i--)
    {
        while (top > 0 && a[stk[top]] <= a[i])
            top--;

        if (top > 0)
            ans[i] = stk[top];
        else
            ans[i] = 0;

        stk[++top] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}