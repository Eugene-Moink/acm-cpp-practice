#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    vector<ll> a(n);

    ll sum = 0;
    ll min_abs = LLONG_MAX;
    ll neg_cnt = 0;
    for (int i = 0; i < n;i++)
    {
        ll a;
        cin >> a;
        if(a<0)
        {
            neg_cnt++;
            a = -a;
        }
        sum += a;
        min_abs = min(min_abs, a);
    }

    if (neg_cnt % 2 == 0)
    {
        cout << sum << endl;
    }
    else
    {
        cout << sum - min_abs * 2 << endl;
    }
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