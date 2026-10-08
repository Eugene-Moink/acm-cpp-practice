#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    ll base = M / N;
    ll rem = M % N;

    for (int i = 0; i < N; i++)
    {
        if (i < rem)
            cout << base + 1 << '\n';
        else
            cout << base << '\n';
    }
    cout << '\n';
    return 0;
}