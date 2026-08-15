#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    string s;
    cin >> s;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    string period;
    int hour12;

    if (h == 0) 
    {
        hour12 = 12;
        period = "AM";
    } 
    else if (h == 12) 
    {
        hour12 = 12;
        period = "PM";
    } 
    else if (h < 12)
    {
        hour12 = h;
        period = "AM";
    } 
    else 
    {
        hour12 = h - 12;
        period = "PM";
    }

    cout << setw(2) << setfill('0') << hour12 << ":"
         << setw(2) << setfill('0') << m << " "
         << period << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        moink();
    }
    return 0;
}