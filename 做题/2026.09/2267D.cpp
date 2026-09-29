#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> odd_pos, even_pos;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i % 2 == 0)
            odd_pos.push_back(x);
        else
            even_pos.push_back(x);
    }
    sort(odd_pos.begin(), odd_pos.end());
    sort(even_pos.begin(), even_pos.end());

    int odd_idx = 0, even_idx = 0;
    vector<int> ans(n);
    int l = 0, r = n - 1;

    while (l <= r)
    {
        if (l == r)
        {
            if (l % 2 == 0)
                ans[l] = odd_pos[odd_idx++];
            else
                ans[l] = even_pos[even_idx++];
        }
        else
        {
            bool left_odd = (l % 2 == 0);
            bool right_odd = (r % 2 == 0);

            if (left_odd == right_odd)
            {
                if (left_odd)
                {
                    int a1 = odd_pos[odd_idx++], a2 = odd_pos[odd_idx++];
                    ans[l] = min(a1, a2);
                    ans[r] = max(a1, a2);
                }
                else
                {
                    int a1 = even_pos[even_idx++], a2 = even_pos[even_idx++];
                    ans[l] = min(a1, a2);
                    ans[r] = max(a1, a2);
                }
            }
            else
            {
                if (left_odd)
                {
                    ans[l] = odd_pos[odd_idx++];
                    ans[r] = even_pos[even_idx++];
                }
                else
                {
                    ans[l] = even_pos[even_idx++];
                    ans[r] = odd_pos[odd_idx++];
                }
            }
        }
        l++;
        r--;
    }

    bool ok = true;
    int k = 0;
    while (k + 1 < n && ans[k] < ans[k + 1])
        k++;
    for (int i = k; i + 1 < n; i++)
    {
        if (ans[i] <= ans[i + 1])
        {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}