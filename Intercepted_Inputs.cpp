#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int k;
    cin >> k;
    int T = k;
    map<int,int>cnt;
    while(T--)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for(auto &p : cnt)
    {
        int n = p.first;
        if ((k - 2) % n == 0)
        {
            int m = (k - 2) / n;
            if (cnt.count(m))
            {
                bool ok = 0;
                if (n == m)
                {
                    if(cnt[n]>=2)
                        ok = 1;
                }
                if (n != m)
                {
                    if(cnt[m]>=1&&cnt[n]>=1)
                        ok = 1;
                }
                cout << n << " " << m << '\n';
                return;
            }
        }
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
        moink();
    }
    return 0;
}