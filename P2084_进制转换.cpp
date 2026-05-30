#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ll m;
    cin >> m;
    string num;
    cin >> num;

    int len = (int)num.size();
    bool first = true;
    for (int i = 0; i < len; i++) 
    {
        if(num[i]=='0')
        {
            continue;
        }
        int power = len - 1 - i;

        if(!first)
        {
            cout << "+";
        }
        first = false;

        cout << num[i] << "*" << m << "^" << power;
    }
    return 0;
}