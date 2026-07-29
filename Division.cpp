#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void moink()
{
    int sc;
    cin >> sc;
    if(sc>=1900)
    {
        cout << "Division 1" << endl;
        return;
    }
    else if(sc>=1600&&sc<=1899)
    {
        cout << "Division 2" << endl;
        return;
    }
    else if(sc>=1400&&sc<=1599)
    {
        cout << "Division 3" << endl;
    }
    else
    {
        cout << "Division 4" << endl;
    }
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