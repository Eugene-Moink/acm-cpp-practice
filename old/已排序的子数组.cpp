#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int last = a[0], cnt = 1, dire = 0;

    for (int i = 1; i < n; i++)
    {
        if (dire == 0)
        {
            if (a[i] > last)
                dire = 1;
            else if (a[i] < last)
                dire = -1;
        }

        else if (dire == 1)
        {
            if (a[i] < last)
            {
                cnt++;
                dire = 0;
            }
        }

        else if (dire == -1)
        {
            if (a[i] > last)
            {
                cnt++;
                dire = 0;
            }
        }
        last = a[i];
    }
    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}