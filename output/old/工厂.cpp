#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int a, m;
    cin >> a >> m;
    int cur = a % m;

    unordered_set<int> had;
    had.insert(cur);

    while(1)
    {
        if(cur==0)
        {
            cout << "Yes" << endl;
            return;
        }

        cur = (cur + cur) % m;
        if(had.count(cur))
        {
            cout << "No" << endl;
            return;
        }
        had.insert(cur);
    }
}

int main()
{
    moink();
    return 0;
}