#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> number;
    for (int i = 0; i < 3;i++)
    {
        int num;
        cin >> num;
        number.push_back(num);
    }

    sort(number.begin(), number.end());
    int a = number[0];
    int b = number[1];
    int c = number[2];

    int common = __gcd(a, c);

    cout << a / common << "/" << c / common << endl;

    return 0;
}