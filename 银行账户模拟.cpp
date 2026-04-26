#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin >> m;

    long long total=0;
    for (int i = 0; i < m;i++)
    {
        string c_q;
        long long number;
        cin >> c_q >> number;

        if(c_q=="deposit")
        {
            total += number;
        }

        else if(c_q=="withdraw")
        {
            total -= number;
        }
    }

    cout << total << endl;
    return 0;
}