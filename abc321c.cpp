#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> ans;
void dfs(ll cur, int last)
{
    ans.push_back(cur);
    for (int i = last - 1; i >= 0; i--)
    {
        dfs(cur * 10 + i, i);
    }
}

void moink()
{
    int k;
    cin >> k;
    cout << ans[k - 1];
}

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        dfs(i, i);
    }
    sort(ans.begin(), ans.end());
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}