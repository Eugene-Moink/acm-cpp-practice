#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int u = 0, d = 0;

    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 'f' && s2[i] == 'o')
            u++;

        else if (s1[i] == 'o' && s2[i] == 'f')
        {
            d++;
        }
    }
    cout << abs(u - d) % 2 << '\n';
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