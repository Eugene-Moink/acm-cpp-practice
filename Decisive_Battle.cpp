#include<bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    string war;
    cin >> war;
    ll East = 0;
    ll West = 0;
    for (ll i = 0; i < war.size();i++)
    {
        if(war[i]=='E')
        {
            East++;
        }
        else
        {
            West++;
        }
    }

    if(West>East)
    {
        cout << "West" << endl;
    }
    else
    {
        cout << "East" << endl;
    }
    return 0;
}