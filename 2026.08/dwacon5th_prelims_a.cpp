#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    double avg = (double)sum / n;
    int ans = -1;
    double diff = 1000;
    for (int i = 0; i < n; i++)
    {
        double cur = abs(a[i] - avg);
        if (cur < diff)
        {
            diff = cur;
            ans = i;
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