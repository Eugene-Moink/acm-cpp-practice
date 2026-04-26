#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    long long sum = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    cout << sum << "\n";
    cout << pow(sum, 2) << "\n";
    cout << pow(sum, 3) << "\n";
    return 0;
}