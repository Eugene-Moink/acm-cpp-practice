#include<iostream>
#include<string>
using namespace std;

int calculateValue(const string& name)
{
    int number = 1;

    for (int i = 0; i < name.size();i++)
    {
        int temp = name[i] - 'A' + 1;
        number = (number * temp) % 47;
    }

    return number;
}

int main()
{
    string star, Duiwu;
    cin >> star >> Duiwu;

    int star_num = calculateValue(star);
    int Duiwu_num = calculateValue(Duiwu);

    if(star_num==Duiwu_num)
    {
        cout << "GO" << endl;
    }

    else
        cout << "STAY" << endl;

    return 0;
}