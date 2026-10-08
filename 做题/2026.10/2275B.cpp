#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<int> st;
    vector<bool> printed(n + 1, false);

    for (int i = 0; i < n; i++)
    {
        int doc = i + 1;
        if (s[i] == '1')
        {
            st.push(doc);
        }
        else if (s[i] == '2')
        {
            if (!st.empty())
            {
                int top = st.top();
                st.pop();
                printed[top] = true;
            }
            else
            {
                printed[doc] = true;
            }
        }
        else if (s[i] == '3')
        {
            printed[doc] = true;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!printed[i])
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); i++)
    {
        if (i > 0)
            cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}