#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, T;
    cin >> n >> T;

    ll ans = 0;
    int pre_t;
    for (int i = 0; i < n;i++)
    {
        int cur_t;
        cin >> cur_t;

        if (i == 0)
        {
            ans = T;
        }

        else
        {
            int gap = cur_t - pre_t;
            ans += min(gap, T);
        }
        pre_t = cur_t;
    }
    cout << ans << endl;
}

int main()
{
    moink();
    return 0;
}