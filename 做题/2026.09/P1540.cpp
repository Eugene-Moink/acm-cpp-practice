#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int m, n;
    cin >> m >> n;

    vector<bool> seen(1005, false);
    queue<int> q;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int word;
        cin >> word;
        if (!seen[word])
        {
            ans++;
            if ((int)q.size() == m)
            {
                seen[q.front()] = false;
                q.pop();
            }
            q.push(word);
            seen[word] = true;
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