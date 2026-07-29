#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, q;
    cin >> n >> q;
    vector<int> ball(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n;i++)
    {
        ball[i] = i + 1;
        pos[i + 1] = i;
    }

    while(q--)
    {
        int x;
        cin >> x;

        int idx = pos[x];
        int next;
        if (idx == n - 1)
        {
            next = idx - 1;
        }
        else
        {
            next = idx + 1;
        }

        swap(ball[idx], ball[next]);
        pos[ball[idx]] = idx;
        pos[ball[next]] = next;
    }

    for (int a : ball)
    {
        cout << a << " ";
    }
}

int main()
{
    moink();
    return 0;
}