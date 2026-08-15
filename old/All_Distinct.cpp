#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int n;
    cin >> n;
    set<int> seen;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        seen.insert(x);
    }

    if (((int)seen.size() % 2) == (n % 2))
    {
        cout << seen.size() << endl;
    }
    else
    {
        cout << seen.size() - 1 << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}