#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;
    for(auto &p : cnt)
    {
        if(p.second % 2 == 1)
            ans++;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}