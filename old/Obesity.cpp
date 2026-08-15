#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll h, w;
    cin >> h >> w;
    double ans = w / ((double)h * h / 10000);
    if (ans >= 25)
    {
        cout << "Yes" << endl;
    }

    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    moink();
    return 0;
}