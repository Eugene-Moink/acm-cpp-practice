#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int a, b;
    cin >> a >> b;
    cout << max(a, b) + abs(a - b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}