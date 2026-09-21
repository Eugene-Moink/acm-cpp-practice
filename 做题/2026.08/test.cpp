#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void moink()
{
    int N, D;
    cin >> N >> D;
    vector<ll> sum(N, 0);
    for (int i = 1; i <= D; i++)
    {
        int a;
        cin >> a;
        sum[a] += i;
    }
    for (int i = 0; i < N; i++)
    {
        cout << sum[i] << (i == N - 1 ? '\n' : ' ');
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    moink();
    return 0;
}