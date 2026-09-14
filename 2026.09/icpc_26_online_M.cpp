#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    unordered_map<string, int> cnt;
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        string s;
        cin >> s;
        cnt[s]++;
    }

    while (m--)
    {
        string s;
        cin >> s;
        if (cnt[s] == 1)
        {
            cout << "OK\n";
            cnt[s]++;
        }
        else if (cnt[s] >= 1)
            cout << "REPEAT\n";
        else
            cout << "WRONG\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}