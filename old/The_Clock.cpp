#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

bool check(int h,int m)
{
    int new_m = (m % 10) * 10 + (m / 10);
    return new_m == h;
}

void moink()
{
    string s;
    int x;
    cin >> s >> x;

    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));

    int ans = 0;
    int cur_min = hh * 60 + mm;
    int start_min = cur_min;

    if(check(hh,mm))
        ans++;

    cur_min = (cur_min + x) % 1440;

    while(start_min != cur_min)
    {
        int cur_h = (cur_min / 60) % 24;
        int cur_m = cur_min % 60;
        if(check(cur_h, cur_m))
        {
            ans++;
        }
        cur_min = (cur_min + x) % 1440;
    }
    cout << ans << endl;
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