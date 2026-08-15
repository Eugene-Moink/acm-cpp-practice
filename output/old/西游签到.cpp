#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "Y" << endl;
        return;
    }

    ll n = a.size();
    ll left = 0;
    ll right = n - 1;

    while (left < n && a[left] == b[left])
    {
        left++;
    }
    while (right >= 0 && a[right] == b[right])
    {
        right--;
    }

    ll l = left, r = right;
    while (l <= r)
    {
        if (a[l] != b[r] || a[r] != b[l])
        {
            cout << "N" << endl;
            return;
        }
        l++;
        r--;
    }
    cout << "Y" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}