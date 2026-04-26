#include<bits/stdc++.h>
using namespace std;

int main()
{
    int weenkday, n;
    cin >> weenkday >> n;

    int result = (weenkday + n % 7);
    if(result<=7)
    {
        cout << result << endl;
    }

    else
    {
        cout << result - 7 << endl;
    }

    return 0;
}