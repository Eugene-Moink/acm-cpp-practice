#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

vector<int> nums;
void get(int cur,int limit)
{
    if(cur>limit)
        return;

    if (cur != 1)
    {
        nums.push_back(cur);
    }
    get(cur * 10, limit);
    get(cur * 10 + 1, limit);
}

bool check(ll x)
{
    if(x==1)
        return 1;

    for (int d : nums)
    {
        if(d>x)
        {
            continue;
        }
        if (x % d == 0 &&check(x / d))
        {
            return 1;
        }
    }
    return 0;
}

void moink()
{
    ll n;
    cin >> n;
    cout << (check(n) ? "YES" : "NO") << endl;
}

int main()
{
    get(1, 1000000000);
    sort(nums.begin(), nums.end());
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}