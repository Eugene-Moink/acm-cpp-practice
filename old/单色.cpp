#include <bits/stdc++.h>
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        cnt[c]++;
    }

    int max_cnt = 0;
    for (int i = 1; i <= n; i++)
        max_cnt = max(max_cnt, cnt[i]);

    cout << n - max_cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}