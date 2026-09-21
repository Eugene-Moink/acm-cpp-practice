#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int x;
    int ans = 0;
    cin >> x;

    for (int c : a)
    {
        if (x < 0)
            break;
        if (c <= x)
        {
            ans++;
            x -= c;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}