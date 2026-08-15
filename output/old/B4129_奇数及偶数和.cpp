#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll odd = (n + 1) / 2;
    ll even = n / 2;

    ll odd_ans = odd * odd;
    ll even_ans = even * (even + 1);
    cout << odd_ans << " "<<even_ans << endl;
    return 0;
}