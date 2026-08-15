#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int new_l = max(l, -m);
    int new_r = new_l + m;
    cout << new_l << " " << new_r << endl;
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