#include<bits/stdc++.h>
using namespace std;
int main()
{
    string time_str;
    getline(cin, time_str);

    int hh, mm;
    stringstream ss(time_str);
    char colon;

    ss >> hh >> colon >> mm;

    if(hh<12||(hh==12&&mm==0))
    {
        cout << "Only ";
        cout << setw(2) << setfill('0') << hh << ":";
        cout << setw(2) << setfill('0') << mm << "." << "  Too early to Dang." << endl;
    }

    if(hh==12&&mm>0)
    {
        cout << "Dang" << endl;
    }

    if(hh>12)
    {
        if(mm==0)
        {
            int temp = hh - 12;
            for (int i = 0; i < temp;i++)
            {
                cout << "Dang";
            }
        }

        else
        {
            int temp = hh - 11;
            for (int i = 0; i < temp;i++)
            {
                cout << "Dang";
            }
        }
    }

    return 0;
}