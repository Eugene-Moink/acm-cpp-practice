#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> d(1005, 0); 
    for (int i = 0; i < n; i++)
    {
        int s, t, b;
        cin >> s >> t >> b;
        d[s] += b;
        d[t] -= b;
    }

    long long cur = 0, ans = 0;
    for (int time = 1; time <= 1000; time++) 
    {
        cur += d[time];
        ans = max(ans, cur);
    }

    cout << ans << endl;
}