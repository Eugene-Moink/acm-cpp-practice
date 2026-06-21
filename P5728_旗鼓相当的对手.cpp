#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

struct student
{
    ll chinese;
    ll math;
    ll english;
    ll total;
};

int main()
{
    ll n;
    cin >> n;
    vector<student> st(n);

    ll cnt = 0;
    for (int i = 0; i < n;i++)
    {
        cin >> st[i].chinese >> st[i].math >> st[i].english;

        st[i].total = st[i].chinese + st[i].math + st[i].english;
    }

    for (int i = 0; i < n;i++)
    {
        for (int j = i + 1; j < n;j++)
        {
            if (abs(st[i].chinese - st[j].chinese) <= 5 &&
                    abs(st[i].math - st[j].math) <= 5 &&
                    abs(st[i].english - st[j].english) <= 5 &&
                    abs(st[i].total - st[j].total) <= 10)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}