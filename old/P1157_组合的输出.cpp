#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int n, r;
vector<int> cur;

void dfs(int start)
{
    if((int)cur.size()==r)
    {
        for (int v : cur) cout << setw(3) << v;
        cout << endl;
        return;
    }

    for (int x = start; x <= n;x++)
    {
        cur.push_back(x);
        dfs(x + 1);
        cur.pop_back();
    }
}

int main()
{
    cin >> n >> r;
    dfs(1);
    return 0;
}