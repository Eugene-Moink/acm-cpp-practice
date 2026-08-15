#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int memo[1000];

void moink()
{
    int n;
    cin >> n;
    memo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        memo[i] = 1;
        for (int j = 1; j <= i / 2; j++)
            memo[i] += memo[j];
    }
    cout << memo[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    moink();
    return 0;
}