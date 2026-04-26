#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
    long long a, b;
    cin >> a >> b;
    long long result = a * b;
    if(result%2==0)
    {
        cout << "Even" << endl;
    }

    else
    {
        cout << "Odd" << endl;
    }

    return 0;
}