#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> boy(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> boy[i];
    }

    int m;
    cin >> m;
    vector<int> girl(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> girl[i];
    }

    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());

    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m)
    {
        if (abs(boy[i] - girl[j]) <= 1)
        {
            i++, j++, ans++;
        }
        else if (boy[i] < girl[j] - 1)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}