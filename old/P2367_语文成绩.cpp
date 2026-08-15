#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;
    vector<int> gpa(n + 1);
    vector<long long> d(n + 2, 0);

    for (int i = 1; i <= n;i++)
    {
        cin >> gpa[i];
    }

    while(p--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }

    ll add = 0;
    ll result = LLONG_MAX;

    for (int i = 1; i <= n;i++) 
    {
        add += d[i];
        ll cur = gpa[i] + add;
        result = min(result, cur);
    }
    cout << result << endl;
    return 0;
}