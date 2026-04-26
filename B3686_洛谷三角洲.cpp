#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, z;
    cin >> x >> y >> z;
    
    int a_to_b = min(x,z+y);
    int b_to_c = min(y, x + z);

    int a_to_c = min(x+y,z);

    cout << a_to_b << endl;
    cout << b_to_c << endl;
    cout << a_to_c << endl;

    return 0;
}