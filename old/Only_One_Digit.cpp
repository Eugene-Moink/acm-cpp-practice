#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    string s;
    cin >> s;
    char val_min = '9';
    for (char c : s)
    {
        if (c >= '0' &&c <= '9')
        {
            val_min = min(val_min, c);
        }
    }
    cout << val_min << endl;
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