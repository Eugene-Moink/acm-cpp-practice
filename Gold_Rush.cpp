#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool check(int cur,int target)
{
    if(cur == target)
        return 1;
    if(cur < target)
        return 0;
    if (cur % 3 != 0)
        return 0;

    return check(cur / 3, target) || check(cur * 2 / 3, target);
}

void moink()
{
    int n, m;
    cin >> n >> m;

    if(check(n,m))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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