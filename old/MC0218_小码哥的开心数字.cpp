#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    string number;
    cin >> number;
    ll temp_1 = stol(number);

    reverse(number.begin(), number.end());
    ll temp_2 = stol(number);

    cout << temp_2 << endl;
    if(temp_1>temp_2)
    {
        cout << "False" << endl;
    }
    else{
        cout << "True" << endl;
    }

    return 0;
}