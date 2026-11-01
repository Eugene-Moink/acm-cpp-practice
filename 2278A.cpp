#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    int n, m;
    cin >> n >> m;
    string p, q;
    cin >> p >> q;

    vector<int> cntP(26, 0);
    vector<int> cntQ(26, 0);

    for (char c : p)
        cntP[c - 'a']++;
    for (char c : q)
        cntQ[c - 'a']++;

    bool ok = true;

    for (int i = 0; i < 26; i++)
    {
        if (i == 's' - 'a' || i == 'i' - 'a' || i == 'x' - 'a')
        {
            if (cntP[i] - cntQ[i] != 1)
            {
                ok = false;
                break;
            }
        }

        else
        {
            if (cntP[i] != cntQ[i])
            {
                ok = false;
                break;
            }
        }
    }

    if (ok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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