#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll max_eat(ll x)
{
    ll eaten = x;
    ll sticks = x;

    while (sticks >= 3)
    {
        ll new_add = sticks / 3;
        eaten += new_add;
        sticks = sticks % 3 + new_add;
    }

    return eaten;
}

int main()
{
    ll n;
    cin >> n;

    ll left = 1, right = n;
    while(left<right)
    {
        ll mid = left + (right - left) / 2;
        if(max_eat(mid)>=n)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << left << endl;
    return 0;
}