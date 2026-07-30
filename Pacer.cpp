#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, m;
    cin >> n >> m;
    int px = 0, py = 0;
    int point = 0;
    while(n--)
    {
        int x, y;
        cin >> x >> y;
        point += x - px;
        if (((x - px + 2) % 2) != ((y - py + 2) % 2))
        {
            point--;
        }
        px = x, py = y;
    }
    if (px != m)
    {
        point += m - px;
    }
    cout << point << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
}