#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll min_num = LLONG_MAX;
    ll max_num = 0;

    for (int i = 1; i <= n;i++)
    {
        ll num;
        cin >> num;
        min_num = min(min_num, num);
        max_num = max(max_num, num);
    }

    cout << max_num - min_num << endl;
    return 0;
}