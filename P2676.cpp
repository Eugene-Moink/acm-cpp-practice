#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long b;
    cin >> n >> b;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    sort(h.begin(), h.end(), greater<int>()); // 从大到小

    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        sum += h[i];
        cnt++;
        if (sum >= b)
            break;
    }

    cout << cnt << '\n';
    return 0;
}