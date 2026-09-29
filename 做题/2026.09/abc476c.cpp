#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq; // 小根堆

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        pq.push(x);
        if (pq.size() > 3)
            pq.pop();

        if (i >= 2)
            cout << pq.top() << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}