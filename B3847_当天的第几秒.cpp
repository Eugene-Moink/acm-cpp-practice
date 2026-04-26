#include<bits/stdc++.h>
using namespace std;
int main()
{
    int hh, mm, ss;
    char am_or_pm;
    cin >> hh >> mm >> ss >> am_or_pm;
    int total = hh * 60 * 60 + mm * 60 + ss;
    if(am_or_pm=='P')
    {
        total += 12 * 60 * 60;
    }

    cout << total << endl;
    return 0;
}