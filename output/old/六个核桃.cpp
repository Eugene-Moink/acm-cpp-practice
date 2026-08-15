#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n, m;
    cin >> n >> m;

    vector<int> result(n);
    int shift = min(m, n / 2);
    for (int i = 0; i < n;i++)
    {
        result[i] = (i + shift) % n + 1;
    }

    for(int a  : result)
    {
        cout << a << " ";
    }
}

int main()
{
    moink();
    return 0;
}