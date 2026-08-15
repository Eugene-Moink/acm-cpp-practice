#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll> pre(n + 1, 0);
        for (int i = 1; i <= n;i++)
        {
            ll num;
            cin >> num;
            pre[i] = pre[i - 1] + num;
        }
        double best = 0;
        for (int l = 1; l <= n; l++) 
        {
            for (int r = l; r <= n; r++) 
            {
                long long sum = pre[r] - pre[l - 1];
                double avg = 1.0 * sum / (r - l + 1);
                best = max(best, avg);
            }
        }
        cout << (long long)(best + 1e-9) << endl;
    }
}