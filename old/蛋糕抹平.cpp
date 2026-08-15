#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        ll pref = 0;
        ll best = LLONG_MAX;

        for(int i = 0; i < n; i++)
        {
            pref += a[i];
            best = min(best, pref / (i + 1));

            if(i) cout << ' ';
            cout << best;
        }
        cout << endl;
    }
    return 0;
}