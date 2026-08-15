#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
    ll price;
    char a, b;
    cin >> price >> a >> b;
    ll result = price;

    if ((a == 'B' && b == 'C') || (a == 'C' && b == 'B'))
    {
        result = result * 6 / 10; 
    }   

    else if (a == 'B' || b == 'B')
    {
        result = result * 8 / 10; 
    }
    
    else if (a == 'C' || b == 'C')
    {
        result = result * 7 / 10; 
    }

    cout << result << endl;
}

int main()
{
    solve();
    return 0;
}