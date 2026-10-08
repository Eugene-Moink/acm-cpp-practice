#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> x(n), breed(n);
    vector<int> alls;

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> breed[i];
        alls.push_back(breed[i]);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    int K = alls.size();

    for (int i = 0; i < n; i++)
        breed[i] = lower_bound(alls.begin(), alls.end(), breed[i]) - alls.begin() + 1;

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b)
         { return x[a] < x[b]; });

    vector<int> cnt(K + 1, 0);
    int types = 0, l = 0, ans = INT_MAX;

    for (int r = 0; r < n; r++)
    {
        int b = breed[idx[r]];
        if (cnt[b] == 0)
            types++;
        cnt[b]++;

        while (types == K)
        {
            ans = min(ans, x[idx[r]] - x[idx[l]]);
            int lb = breed[idx[l]];
            cnt[lb]--;
            if (cnt[lb] == 0)
                types--;
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