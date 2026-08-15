#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    ll h, w;
    cin >> h >> w;
    vector<string> a(h+1);
    for (ll i = 1; i <= h;i++)
    {
        string tmp;
        cin >> tmp;
        a[i] = " " + tmp;
    }

    int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
    for (ll i = 1; i <= h;i++)
    {
        for (ll j = 1; j <= w;j++)
        {
            if (a[i][j] == '.')
            {
                int cnt = 0;
                for (int d = 0; d < 8; ++d)
                {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 1 && ni <= h && nj >= 0 && nj < w)
                    {
                        if (a[ni][nj] == '#')
                            cnt++;
                    }
                }
                a[i][j] = '0' + cnt;
            }
        }
    }
    for (ll i = 1; i <= h;i++)
    {
        cout << a[i].substr(1) << endl;
    }
}

int main()
{
    moink();
    return 0;
}