#include<bits/stdc++.h>
using namespace std;

int main()
{
    int YY, mm;
    cin >> YY >> mm;
    if((YY%400==0)||(YY%4==0&&YY%100!=0))
    {
        if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
        {
            cout << "31" << endl;
        }
        else if(mm==2)
        {
            cout << "29" << endl;
        }
        else
        {
            cout << "30" << endl;
        }
    }

    else
    {
        if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
        {
            cout << "31" << endl;
        }
        else if(mm==2)
        {
            cout << "28" << endl;
        }
        else
        {
            cout << "30" << endl;




        }
    }

    return 0;
}