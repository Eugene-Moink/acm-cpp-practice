#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int a, b;
    cin >> a >> b;
    int cnt = 1, ans = 0;
    while(cnt < b)
    {
        cnt += a - 1;
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}