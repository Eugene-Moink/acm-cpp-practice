#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
void solve()
{
    vector<int> a(32);
    for (int &x : a)
        cin >> x;

    int max_val1 = 0, max_val2 = 0;
    int id1 = 0, id2 = 0;
    for (int i = 0; i < 16; i++)
    {
        if (a[i] > max_val1)
        {
            max_val1 = a[i];
            id1 = i + 1;
        }
    }

    for (int i = 16; i < 32; i++)
    {
        if (a[i] > max_val2)
        {
            max_val2 = a[i];
            id2 = i + 1;
        }
    }

    if (max_val1 < max_val2)
    {
        cout << id1 << '\n';
    }
    else
    {
        cout << id2 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}