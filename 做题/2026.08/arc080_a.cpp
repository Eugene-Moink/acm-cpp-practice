#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
    }

    int c4 = 0, c2 = 0, c1 = 0;
    for (int x : a)
    {
        if (x % 4 == 0)
            c4++;
        else if (x % 2 == 0 && x % 4 != 0)
            c2++;
        else
            c1++;
    }

    if (c1 == 0)
    {
        cout << "Yes\n";
        return;
    }
    else
    {
        if (c2 == 0 && (c4 >= c1 - 1))
        {
            cout << "Yes\n";
            return;
        }
        else if (c2 > 0 && c4 >= c1)
        {
            cout << "Yes\n";
        }

        else
            cout << "No\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}