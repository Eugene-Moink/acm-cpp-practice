#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int bp = (b - a + 12) % 12;
    int cp = (c - a + 12) % 12;
    int dp = (d - a + 12) % 12;

    if ((cp < bp) != (dp < bp))
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}