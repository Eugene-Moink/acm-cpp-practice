#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> cnt(n + 1, 0);
    int mx = 0, ntx = 1;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        if (cnt[x] < mx || mx == 0)
        {
            b[i] = x;
            cnt[x]++;
            if(cnt[x]>mx)
                mx = cnt[x];
        }
        else
        {
            while(cnt[ntx]>0)
                ntx++;

            b[i] = ntx;
            cnt[ntx] = 1;
            ntx++;
        }
    }
    for(int x : b)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}