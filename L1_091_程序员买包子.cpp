#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    string x;

    cin >> n >> x >> m >> k;

    if(k == n)
    {
        cout << "mei you mai " << x << " de" << endl;
    }
    else if(k == m)
    {
        cout << "kan dao le mai " << x << " de" << endl;
    }
    else
    {
        cout << "wang le zhao mai " << x << " de" << endl;
    }

    return 0;
}