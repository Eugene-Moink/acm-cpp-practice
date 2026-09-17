#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string best_name = "";
    int best_score = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        int t1, t2;
        char c1, c2;
        int num;

        cin >> s >> t1 >> t2 >> c1 >> c2 >> num;
        int sc = 0;
        if (t1 > 80 && num != 0)
            sc += 8000;
        if (t1 > 85 && t2 > 80)
            sc += 4000;
        if (t1 > 90)
            sc += 2000;
        if (t1 > 85 && c2 == 'Y')
            sc += 1000;
        if (t2 > 80 && c1 == 'Y')
            sc += 850;

        if (sc > best_score)
        {
            best_score = sc;
            best_name = s;
        }
        sum += sc;
    }
    cout << best_name << '\n'
         << best_score << '\n'
         << sum << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}