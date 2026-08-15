#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    int pre_t = 0, pre_x = 0, pre_y = 0;
    for (int i = 0; i < n;i++)
    {
        int cur_t, cur_x, cur_y;
        cin >> cur_t >> cur_x >> cur_y;

        int dt = cur_t - pre_t;
        int dist = abs(cur_x - pre_x) + abs(cur_y - pre_y);

        if (dist > dt || (dt - dist) % 2 != 0)
        {
            cout << "No" << endl;
            return;
        }
        pre_t = cur_t;
        pre_x = cur_x;
        pre_y = cur_y;
    }
    cout << "Yes" << endl;
}

int main()
{
    moink();
    return 0;
}