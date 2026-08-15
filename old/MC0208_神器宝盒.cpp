#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int main()
{
    ll number;
    cin >> number;
    if(number%10==0)
    {
        number = 0;
    }
    else{
        number *= 2;
    }
    cout << number;
    return 0;
}