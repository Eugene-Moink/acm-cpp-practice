#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int id = -1;
    int n;
    cin >> n;
    string max_vote = "";
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (max_vote == "" || s.size() > max_vote.size() || (s.size() == max_vote.size() && s > max_vote))
        {
            max_vote = s;
            id = i;
        }
    }
    cout << id << '\n'
         << max_vote << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}