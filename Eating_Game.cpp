#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<ll> num(n + 1, 0);
        ll total = 0;

        for (int i = 1; i <= n;i++)
        {
            cin >> num[i];
            total += num[i];
        }

        vector<int> seen(n + 1, 0);
        for (int start = 1; start <= n;start++)
        {
            auto a = num;
            int rem = total;
            int cur = start;
            int last = -1;

            while (rem>0)
            {
                if(a[cur]>0)
                {
                    a[cur]--;
                    rem--;
                    last = cur;
                }

                cur++;
                if(cur>n)
                    cur = 1;
            }
            seen[last] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += seen[i];
        cout << ans << endl;
    }
    return 0;
}