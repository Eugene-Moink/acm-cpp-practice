#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> bulidNext(const string &p)
{
    int m = p.size();
    vector<int> nxt(m, 0);
    for (int i = 0, j = 0; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = nxt[j - 1];
        if (p[i] == p[j])
            nxt[i] = j;
    }
    return nxt;
}

int KMP(const string &s, const string &p)
{
    if (p.empty())
        return 0;

    vector<int> nxt = bulidNext(p);
    int n = s.size(), m = p.size();
    int cnt = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
            j = nxt[j - 1];
        if (s[i] == p[j])
            j++;
        if (j == m)
        {
            cnt++;
            j = nxt[j - 1];
        }
    }
    return cnt;
}

void solve()
{
    string s;
    cin >> s;

    cout << KMP(s, "fjcpc") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}