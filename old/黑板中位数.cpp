#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    ll x, q;
    cin >> x >> q;
    priority_queue<ll> left;
    priority_queue<ll, vector<ll>, greater<ll>> right;

    left.push(x);
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        if(a <= left.top())
            left.push(a);
        else
            right.push(a);

        if(b <= left.top())
            left.push(b);
        else
            right.push(b);

        if (left.size() < right.size() + 1) 
        {
            left.push(right.top());
            right.pop();
        }
        if (left.size() > right.size() + 1) 
        {
            right.push(left.top());
            left.pop();
        }
        cout << left.top() << '\n';
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}