#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> cntA(M + 1, 0);
    vector<int> cntB(M + 1, 0);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        cntA[a]++;
        cntB[b]++;
    }

    for (int j = 1; j <= M; j++)
    {
        cout << cntB[j] - cntA[j] << '\n';
    }

    return 0;
}