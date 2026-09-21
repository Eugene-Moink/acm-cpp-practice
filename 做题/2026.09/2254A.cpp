#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int a, b, c;
    cin >> a >> b >> c;
    int rounds = 0;
    while (true)
    {
        if (a == b || b == c || a == c)
        {
            break;
        }

        int mx = max({a, b, c});
        int mn = min({a, b, c});

        if (a == mx)
            a--;
        else if (b == mx)
            b--;
        else
            c--;
        if (a == mn)
            a++;
        else if (b == mn)
            b++;
        else
            c++;

        rounds++;
    }

    cout << rounds << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        moink();
    }
    return 0;
}