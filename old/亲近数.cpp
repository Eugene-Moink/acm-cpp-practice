#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll n;
    cin >> n;

    ll left = 1;
    while (left * 2 <= n)
    {
        left *= 2;
    }

    ll right = left * 2;

    if (n - left <= right - n)
    {
        cout << left << endl;
    }
    else
        cout << right << endl;
}

int main()
{
    moink();
    return 0;
}