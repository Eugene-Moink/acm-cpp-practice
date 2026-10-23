#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    int odd_cnt = 0, even_cnt = 0;
    for (int &x : a)
    {
        cin >> x;
        if (x & 1)
            odd_cnt++;
        else
            even_cnt++;
    }

    if ((odd_cnt == 1 && even_cnt == 1) || (odd_cnt == 3 && even_cnt == 0))
    {
        cout << "Larpity\n";
    }
    else
    {
        cout << "Moggity\n";
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