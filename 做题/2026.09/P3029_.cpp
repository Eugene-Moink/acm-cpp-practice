#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Cow
{
    int pos;
    int type;
};

void solve()
{
    int n;
    cin >> n;

    vector<Cow> cows(n);
    vector<int> allTypes;

    for (int i = 0; i < n; i++)
    {
        cin >> cows[i].pos >> cows[i].type;
        allTypes.push_back(cows[i].type);
    }

    sort(allTypes.begin(), allTypes.end());
    allTypes.erase(unique(allTypes.begin(), allTypes.end()), allTypes.end());

    int K = allTypes.size();

    for (int i = 0; i < n; i++)
    {
        cows[i].type = lower_bound(allTypes.begin(), allTypes.end(), cows[i].type) - allTypes.begin() + 1;
    }

    sort(cows.begin(), cows.end(), [](const Cow &a, const Cow &b)
         { return a.pos < b.pos; });

    vector<int> cnt(K + 1, 0);

    int type = 0;
    int l = 0;
    int ans = INT_MAX;

    for (int r = 0; r < n; r++)
    {
        int t = cows[r].type;
        if (cnt[t] == 0)
            type++;
        cnt[t]++;

        while (type == K)
        {

            ans = min(ans, cows[r].pos - cows[l].pos);
            int lt = cows[l].type;
            cnt[lt]--;
            if (cnt[lt] == 0)
                type--;
            l++;
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