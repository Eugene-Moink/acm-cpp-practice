#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 1; i <= n;i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }

        int best_b = -1;
        int best_idx = -1;

        for (int i = 0; i < n;i++)
        {
            int a = v[i].first;
            int b = v[i].second;
            if (a <= 10 && b > best_b)
            {
                best_b = b;
                best_idx = i + 1;
            }
        }
        cout << best_idx << endl;
    }
    return 0;
}