#include<bits/stdc++.h>
using namespace std;
void moink()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cout << 2 * i - 1 << (i == n ? '\n' : ' ');
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
}