#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }
        vector<int> down;
        for (int i = 0; i < n - 1; i++) 
        {
            if (a[i] > a[i+1]) down.push_back(i);
        }

        long long L = 0;
        for (int i : down)
        {
            L = max(L, a[i] - a[i+1]);
        }

        bool ok = true;

        for (int j = 0; j + 1 < down.size(); j++) {
            int p = down[j];
            int q = down[j + 1];

            long long best = -1;

            for (int t = p + 1; t < q; t++) {
                best = max(best, a[t + 1] - a[t]);
            }

            if (best < L) {
                ok = false;
                break;
            }
        }

        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}