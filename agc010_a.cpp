#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
        if (x % 2 == 0)
            c2++;
        else
            c1++;
    }

    if (c1 % 2 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}